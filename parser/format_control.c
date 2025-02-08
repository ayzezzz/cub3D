/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:39:17 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/07 15:38:51 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static int	is_open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

static int	xpm_loop(t_data *data, char *path)
{
	size_t	i;

	i = ft_strlen(path) - 1;
	if (path[i] == 'm' && path[i - 1] == 'p' && path[i - 2] == 'x'
		&& path[i - 3] == '.')
	{
		if (!is_open_file(path))
		{
			free_xpm_loop(data);
			return (error_message("File 🥺\n"), 0);
		}
		else if ((ft_strncmp(path, ".xpm", ft_strlen(path)) == 0)
			|| (path[i - 4] && path[i - 4] == '/'))
		{
			free_xpm_loop(data);
			return (error_message("File 🥺\n"), 0);
		}
		return (1);
	}
	else
	{
		free_xpm_loop(data);
		return (error_message("File 🥺\n"), 0);
	}
}

int	is_xpm_file(t_data *data)
{
	if (!xpm_loop(data, data->textures.no) || !xpm_loop(data, data->textures.so)
		|| !xpm_loop(data, data->textures.ea) || !xpm_loop(data,
			data->textures.we))
		return (0);
	return (1);
}

static char	*is_xpm_check(char **str, char *path)
{
	int	i;
	int	start;

	start = 0;
	i = 0;
	if (str[1] != NULL)
		return (NULL);
	else
	{
		start = i;
		while (str[0][i] && str[0][i] != 32)
			i++;
		path = ft_substr(str[0], start, i);
		double_str_free(str);
		return (path);
	}
	return (path);
}

char	*find_texture_path(char *clean_str)
{
	char	*path;
	char	**str;

	path = NULL;
	str = ft_split(clean_str, 32);
	path = is_xpm_check(str, path);
	if (!path)
	{
		double_str_free(str);
		return (NULL);
	}
	return (path);
}
