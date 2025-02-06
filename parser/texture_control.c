/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:00:45 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/05 20:29:34 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static void	init_check_list(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
		data->textures.check_list[i++] = 0;
}

static int	is_fill_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->textures.check_list[i] == 0
			|| data->textures.check_list[i] > 1)
			return (0);
		i++;
	}
	return (1);
}

int	set_texture(t_data *data, char *clean_str)
{
	if (clean_str[0] == 'N' && clean_str[1] == 'O' && clean_str[2] == ' ')
		getter_texture(data,clean_str,NO,&data->textures.no);
	else if (clean_str[0] == 'S' && clean_str[1] == 'O' && clean_str[2] == ' ')
		getter_texture(data,clean_str,SO,&data->textures.so);
	else if (clean_str[0] == 'W' && clean_str[1] == 'E' && clean_str[2] == ' ')
		getter_texture(data,clean_str,WE,&data->textures.we);
	else if (clean_str[0] == 'E' && clean_str[1] == 'A' && clean_str[2] == ' ')
		getter_texture(data,clean_str,EA,&data->textures.ea);
	else if ((clean_str[0] == 'F' && clean_str[1] == ' ')
		&& (data->textures.check_list[F] += 1))
		data->textures.f = find_color_num(clean_str + 2);
	else if ((clean_str[0] == 'C' && clean_str[1] == ' ')
		&& (data->textures.check_list[C] += 1))
		data->textures.c = find_color_num(clean_str + 2);
	if ((!data->textures.no || !data->textures.so || !data->textures.we
			|| !data->textures.ea) && is_fill_textures(data))
		return (1);
	if ((!data->textures.f || !data->textures.c) && is_fill_textures(data))
		return (2);
	return (0);
}

static int	texture_loop(t_data *data, int *i, char *str, int fd)
{
	while (*i < data->cub_map.map_row)
	{
		free(str);
		str = get_next_line(fd);
		(*i)++;
	}
	if (!is_fill_textures(data))
		return (0);
	return (1);
}

void	texture_count_check(t_data *data)
{
	char	*str;
	char	*clean_str;
	int		fd;
	int		i;

	i = 0;
	init_check_list(data);
	fd = open(data->path, O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		clean_str = ft_strtrim(str, " \n");
		if ((clean_str[0] == '0' || clean_str[0] == '1') && !texture_loop(data,
				&i, str, fd))
		{
			free_texture_check(data, str, clean_str, fd);
			error_message("Invalid textures! 🥺\n");
		}
		if (!texture_error(data, clean_str))
		{
			free_texture_check(data, str, clean_str, fd);
			exit(1);
		}
		free(str);
		free(clean_str);
	}
	close(fd);
}
