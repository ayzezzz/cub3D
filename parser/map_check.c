/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:53:49 by zayaz             #+#    #+#             */
/*   Updated: 2025/02/07 14:31:15 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static void	allocate_map(t_data *data)
{
	data->cub_map.map = (char **)malloc((data->cub_map.map_row + 1)
			* sizeof(char *));
	if (data->cub_map.map == NULL)
	{
		free(data);
		error_message("Map allocation failed! 🥺\n");
	}
	data->cub_map.cpymap = (char **)malloc((data->cub_map.map_row + 1)
			* sizeof(char *));
	if (data->cub_map.cpymap == NULL)
	{
		free(data->cub_map.map);
		free(data);
		error_message("Map allocation failed! 🥺\n");
	}
}

static void	fill_map(t_data *data)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(data->path, O_RDONLY);
	line = get_next_line(fd);
	line = go_pass_textures(line, fd);
	allocate_map(data);
	while (line)
	{
		if (line != NULL)
		{
			data->cub_map.map[i] = ft_strdup(line);
			data->cub_map.cpymap[i] = ft_strdup(line);
			free(line);
			i++;
		}
		line = get_next_line(fd);
	}
	free(line);
	data->cub_map.map[i] = NULL;
	data->cub_map.cpymap[i] = NULL;
}

static void	map_row_count(t_data *data, int fd)
{
	char	*line;

	line = NULL;
	fd = open(data->path, O_RDONLY);
	line = get_next_line(fd);
	line = go_pass_textures(line, fd);
	while (line != NULL)
	{
		data->cub_map.map_row++;
		free(line);
		line = get_next_line(fd);
	}
	go_gnl_last(fd, line);
	free(line);
	close(fd);
}

void	map_check(t_data *data)
{
	int	fd;

	fd = open(data->path, O_RDONLY);
	map_row_count(data, fd);
	character_check(data);
	player_check(data);
	fill_map(data);
	player_loc(data);
	map_close_check(data);
	flood_fill_check(data);
	close(fd);
}
