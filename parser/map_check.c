/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:53:49 by zayaz             #+#    #+#             */
/*   Updated: 2025/02/04 13:07:02 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static void allocate_map(t_data *data)
{
    data->cub_map.map = (char **)malloc((data->cub_map.map_row + 1) * sizeof(char *));
    if (data->cub_map.map == NULL)
    {
        error_message("Map allocation failed! 🥺\n");
    }

    data->cub_map.cpymap = (char **)malloc((data->cub_map.map_row + 1) * sizeof(char *));
    if (data->cub_map.cpymap == NULL)
    {
        error_message("Map allocation failed! 🥺\n");
        free(data->cub_map.map);
    }
}

static void fill_map(t_data *data)
{
    char *line;
    int fd;
    int i;

    i = 0;
    fd = open(data->path, O_RDONLY);
    if (fd == -1)
        return;
    line = get_next_line(fd);
    line = go_pass_textures(line, fd); 
    allocate_map(data);
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
    if (fd == -1)
        return;
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
    if (fd == -1)
        return (0);
    map_row_count(data, fd);
    character_check(data);
    player_check(data);
    fill_map(data);
    player_loc(data);
    map_close_check(data);
    flood_fill_check(data);
    close(fd);
    return (1);
}