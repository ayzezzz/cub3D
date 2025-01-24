/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:38:03 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/24 14:03:38 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

int find_height(t_data *data)
 {
    int height;
    int tmp;
    char *line;
    int fd;
    int i;
    
    tmp = 0;
    i = 0;
    height = 0;
    fd = open(data->path, O_RDONLY);
    line = get_next_line(fd); 
    line = go_pass_textures(line, fd);

    while(line)
    {
        i = 0;
        while(line[i]!= '\0')
        {
            if (line[i] && (line[i] != '\n'))
               tmp++;
            if(height < tmp)
                height = tmp;
            tmp = 0;
            i++;
        }
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    printf("height%d:\n",height);
    return(height);
 }

// void map_closde_check(t_data *data)
// {
//     int height;
//     int width;

//     find_height(data);
//     find_width();
    
// }