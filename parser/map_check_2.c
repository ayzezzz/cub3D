/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:47:38 by zayaz             #+#    #+#             */
/*   Updated: 2025/02/06 12:49:48 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static void	check_line_for_invalid_chars(t_data *data, char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E'
			&& line[i] != '\n' && line[i] != '0' && line[i] != '1'
			&& line[i] != 32)
		{
			map_free(data, line, fd);
			error_message("Invalid character! 🥺\n");
		}
		i++;
	}
}

void	character_check(t_data *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(data->path, O_RDONLY);
	line = get_next_line(fd);
	line = go_pass_textures(line, fd);
	if (!line)
	{
		map_free(data, line, fd);
		error_message("Map not found! 🥺\n");
	}
	i = 0;
	while (line)
	{
		check_line_for_invalid_chars(data, line, fd);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	go_gnl_last(fd, line);
	close(fd);
}

static void	count_players_in_line(char *line, int *player_count)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
			(*player_count)++;
		i++;
	}
}

void	player_check(t_data *data)
{
	int		player_count;
	char	*line;
	int		fd;

	player_count = 0;
	fd = open(data->path, O_RDONLY);
	line = get_next_line(fd);
	line = go_pass_textures(line, fd);
	while (line)
	{
		count_players_in_line(line, &player_count);
		free(line);
		line = get_next_line(fd);
	}
	if (player_count != 1)
	{
		map_free(data, line, fd);
		error_message("Invalid player! 🥺\n");
	}
	free(line);
	close(fd);
}

void	player_loc(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->cub_map.map && data->cub_map.map[i])
	{
		j = 0;
		while (data->cub_map.map[i] && data->cub_map.map[i][j])
		{
			if (data->cub_map.map[i][j] == 'N' || data->cub_map.map[i][j] == 'S'
				|| data->cub_map.map[i][j] == 'E'
				|| data->cub_map.map[i][j] == 'W')
			{
				data->player.p_x = j + 0.5;
				data->player.p_y = i + 0.5;
				data->player.p_dir = data->cub_map.map[i][j];
			}
			j++;
		}
		i++;
	}
}
