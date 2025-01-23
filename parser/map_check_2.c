/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:01:55 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/23 12:17:00 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static int is_texture_start(char *line, int i)
{
    if (((line[i] == 'N' && line[i + 1] == 'O') || 
         (line[i] == 'S' && line[i + 1] == 'O') ||
         (line[i] == 'W' && line[i + 1] == 'E') || 
         (line[i] == 'E' && line[i + 1] == 'A')) && line[i + 2] != ' ')
        return 1;

    if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] != ' ')
        return 1;

    return 0;
}


void is_textures_top(t_data *data)
{
    char *line;
    int fd;
    int i;

    i = 0;
    fd = open(data->path, O_RDONLY);
    line = get_next_line(fd);
    
    while (line)
    {
        i = 0;
        while (line[i] != '\0')
        {
            // Yardımcı fonksiyonu çağırıyoruz
            if (line[i] && is_texture_start(line, i))
            {
                map_free(data, line, fd);
                error_message("Textures not found at the top of the map! 🥺\n");
                return;
            }
            i++;
        }
        free(line);
        line = get_next_line(fd);
    }
}

void    check_line_start_end(t_data *data)
{
    char *line;
    int fd;
    int i;

    i = 0;
    fd = open(data->path, O_RDONLY);
    line = get_next_line(fd);
    
    while (line)
    {
        i = 0;
        while (line[i] != '\0')
        {
            if (line[i] && (line[i] != 32 && line [i] != 1))
            {
                map_free(data, line, fd);
                error_message("Map not closed! 🥺\n");
                return;
            }
            i++;
        }
        free(line);
        line = get_next_line(fd);
    }
}