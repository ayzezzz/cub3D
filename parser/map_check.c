/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:53:49 by zayaz             #+#    #+#             */
/*   Updated: 2025/02/03 16:49:39 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void fill_map(t_data *data)
{
    char *line;
    int fd;
    int i;

    i = 0;
    fd = open(data->path, O_RDONLY);
    line = get_next_line(fd);
    line = go_pass_textures(line, fd);
    data->cub_map.map = (char **)malloc((data->cub_map.map_row + 1) * sizeof(char *));
    data->cub_map.cpymap = (char **)malloc((data->cub_map.map_row + 1) * sizeof(char *));
    while (line)
    {
        if (line != NULL)
        {
            data->cub_map.map[i] = ft_strtrim(line, "\n");
            data->cub_map.cpymap[i] = ft_strtrim(line, "\n");
            free(line);
            i++;
        }
        line = get_next_line(fd);
    }
    free(line);
    data->cub_map.map[i] = NULL;
    data->cub_map.cpymap[i] = NULL;
}

static void map_row_count(t_data *data, int fd)
{
    char *line = NULL;

    fd = open(data->path, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return;
    }
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

int map_check(t_data *data)
{
    int fd;
    fd = open(data->path, O_RDONLY);

    map_row_count(data, fd);
    character_check(data);
    player_check(data);
    fill_map(data);
    player_loc(data);
    map_close_check(data);
    //flood_fill_check(data);
    close(fd);
    return 1;
}