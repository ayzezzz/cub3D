/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:53:49 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/22 15:05:24 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void multi_map_check(int fd)
{
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (line[0] != '\n')
        {   
            error_message("Multi map error! 🥺\n");
            free(line);
            close(fd);
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
                error_message("Invalid character! 🥺\n");
                free(line);
                close(fd);
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
        printf("line:%s\n",line);
        free(line);
        line = get_next_line(fd);
    }
    if(player_count != 1)
    {
        printf("pl:%d\n",player_count);
        error_message("More than one player found! 🥺\n");
        free(line);
        close(fd);
    }
    free(line);
    close(fd);    
}

void map_row_count(t_data *data, int fd)
{ 
    char *line;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if(pass_texture(data, line) && data->map.map_row == 0)
        {
            free(line);
            continue;
        }
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
    multi_map_check(fd);
    character_check(data);
    player_check(data);
    printf("raw: %d", data->map.map_row);
    exit(1);
    return 0;
    // close(fd);
    // player_position();
    // wall_check();
    // blank_check();
    // fill_map();
}