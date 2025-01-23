/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:53:49 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/23 14:27:16 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void multi_map_check(t_data *data, int fd)
{
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (line[0] != '\n')
        {   
            map_free(data, line, fd);
            error_message("Multi map error! 🥺\n");
            break;
        }
        free(line); 
    }
    go_gnl_last(fd, line);
    close(fd);
}


void character_check(t_data *data)
{
    (void)data;
    int fd;
    int i = 0;
    
    char *line;
    fd = open(data->path,O_RDONLY);
    line = get_next_line(fd);
    line = go_pass_textures(data, line, fd);
    while(line)
    {
        i = 0;
        while(line[i]!= '\0')
        {
            if (line[i] != 'N' && line[i] != 'S' && 
                    line[i] != 'W' && line[i] != 'E' && line[i] != 'F' &&
                    line[i] != 'C' && line[i] != '\n' && line[i] != '0' && line[i] != '1' && line[i] != 32)
            {   
                map_free(data, line, fd);
                error_message("Invalid character! 🥺\n");
                break;
            }
            i++;
        }
        free(line);
        line = get_next_line(fd);
    }
    go_gnl_last(fd, line);
    close(fd);
}

void player_check(t_data *data)
{
    int player_count;
    char *line;
    int fd;
    int i;
    
    i = 0;
    player_count = 0;
    fd = open(data->path, O_RDONLY);
    line = get_next_line(fd); 
    line = go_pass_textures(data, line, fd);
    while(line)
    {
        i = 0;
        while(line[i]!= '\0')
        {
            if ( line[i] && (line[i] == 'N' || line[i] == 'S' || 
                    line[i] == 'W' || line[i] == 'E' || line[i] == 'F' ||
                    line[i] == 'C'))
                player_count++;
            i++;
        }
        free(line);
        line = get_next_line(fd);
    }
    if(player_count != 1)
    {
        map_free(data, line, fd);
        error_message("More than one player found! 🥺\n");
    }
    free(line);
    close(fd);    
}

void map_row_count(t_data *data, int fd)
{
    char *line;
    fd = open(data->path,O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line[0] == '\n' && data->map.map_row != 0)
            break;
        data->map.map_row++;
        free(line);
    }
    free(line);
}

int map_check(t_data *data)
{
    int fd;
    fd = open(data->path,O_RDONLY);
     
    map_row_count(data, fd);
    multi_map_check(data, fd);
    character_check(data);
    player_check(data);
    //as
    //map_closed_check();
    //map_close_check(data);
    close(fd);
    return 0;
    //player_position();
    // fill_map();
}