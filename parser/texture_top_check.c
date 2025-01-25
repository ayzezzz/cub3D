/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:01:55 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/23 14:30:44 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static int is_texture_start(char *line, int i)
{
    if (((line[i] == 'N' && line[i + 1] == 'O') ||
         (line[i] == 'S' && line[i + 1] == 'O') ||
         (line[i] == 'W' && line[i + 1] == 'E') ||
         (line[i] == 'E' && line[i + 1] == 'A')) &&
        line[i + 2] != ' ')
        return 1;

    if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] != ' ')
        return 1;

    return 0;
}

int is_textures_top(t_data *data)
{
    char *line;
    int fd;
    int i;

    i = 0;
    fd = open(data->path, O_RDONLY);
    if (fd < 0)
    {
        error_message("Failed to open the file! 🥺 \n");
        return 0;
    }
    line = get_next_line(fd);

    while (line)
    {
        i = 0;
        while (line[i] != '\0')
        {
            if (line[i] && is_texture_start(line, i))
            {
                map_free(data, line, fd);
                error_message("Textures not found at the top of the map! 🥺\n");
                return (0);
            }
            i++;
        }
        free(line);
        line = get_next_line(fd);
    }
    return (1);
}