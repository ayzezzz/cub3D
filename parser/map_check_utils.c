/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:58:06 by zayaz             #+#    #+#             */
/*   Updated: 2025/02/05 18:53:55 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void go_gnl_last(int fd, char *line)
{
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        free(line);
    }
    free(line);
}

static int pass_texture(char *line)
{
    if ((line[0] == 'N' && line[1] && line[1] == 'O') || (line[0] == 'S' && line[1] && line[1] == 'O') ||
        (line[0] == 'W' && line[1] && line[1] == 'E') || (line[0] == 'E' && line[1] && line[1] == 'A') || line[0] == 'F' ||
        line[0] == 'C' || line[0] == '\n')
        return (1);
    return (0);
}

char *go_pass_textures(char *line, int fd)
{
    char *str;

    while (line)
    {
        str = ft_strtrim(line, " ");
        if (pass_texture(str))
        {
            free(str);
            free(line);
            line = get_next_line(fd);
            continue;
        }
        free(str);
        break;
    }
    return (line);
}

void map_free(t_data *data, char *line, int fd)
{
    go_gnl_last(fd, line);
    if(line)
        free(line);
    textures_free(data);
    free(data);
    close(fd);
}
