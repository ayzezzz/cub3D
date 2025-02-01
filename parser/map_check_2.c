/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:47:38 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/27 14:47:41 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static void check_line_for_invalid_chars(t_data *data, char *line, int fd)
{
    int i = 0;

    while (line[i] != '\0')
    {
        if (line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E' &&
            line[i] != '\n' && line[i] != '0' && line[i] != '1' && line[i] != 32)
        {
            map_free(data, line, fd);
            error_message("Invalid character! 🥺\n");
            return;
        }
        i++;
    }
}

void character_check(t_data *data)
{
    char *line;
    int fd = open(data->path, O_RDONLY);

    line = get_next_line(fd);
    line = go_pass_textures(line, fd);

    while (line)
    {
        check_line_for_invalid_chars(data, line, fd);
        free(line);
        line = get_next_line(fd);
    }

    go_gnl_last(fd, line);
    close(fd);
}

static void count_players_in_line(char *line, int *player_count)
{
    int i = 0;

    while (line[i] != '\0')
    {
        if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
            (*player_count)++;
        i++;
    }
}

void player_check(t_data *data)
{
    int player_count = 0;
    char *line;
    int fd = open(data->path, O_RDONLY);

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
        error_message("More than one player found! 🥺\n");
    }
    free(line);
    close(fd);
}
