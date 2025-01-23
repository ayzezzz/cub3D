/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:58:06 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/23 12:14:32 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void go_gnl_last(int fd, char *line)
{
    while(1)
    {
        if((line = get_next_line(fd)) == NULL)
            break;
    }
}

int pass_texture(t_data *data, char *line)
{
    (void)data;
   if (line[0] == 'N' || line[0] == 'S' || 
        line[0] == 'W' || line[0] == 'E' || line[0] == 'F' ||
        line[0] == 'C' || line[0] == '\n')
        return(1);
    return(0);

}

char *go_pass_textures(t_data *data, char *line, int fd)
{
    while(line) 
    {
        if(pass_texture(data, line))
        {
            free(line);
            line = get_next_line(fd);
            continue;
        }
        break;   
    }
    return(line);
}

void map_free(t_data *data, char *line, int fd)
{
    free(line);
    free(data);
    textures_free(data);
    close(fd);
}