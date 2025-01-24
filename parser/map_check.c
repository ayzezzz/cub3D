/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:53:49 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/24 20:27:49 by zayaz            ###   ########.fr       */
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
    data->cub_map.map = (char**)malloc((data->cub_map.map_row + 1) * sizeof(char *));
    data->cub_map.cpymap = (char**)malloc((data->cub_map.map_row + 1) * sizeof(char *));

    while (i < data->cub_map.map_row)
    {
        if (line != NULL) 
        {
            data->cub_map.map[i] = ft_strtrim(line,"\n");
            data->cub_map.cpymap[i] = ft_strtrim(line,"\n");
            free(line);
            i++;
        }
        line = get_next_line(fd);
    }
    data->cub_map.map[i] = NULL;
    data->cub_map.cpymap[i] = NULL;
}

void character_check(t_data *data)
{
    (void)data;
    int fd;
    int i = 0;
    
    char *line;
    fd = open(data->path,O_RDONLY);
    line = get_next_line(fd);
    line = go_pass_textures(line, fd);
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
    line = go_pass_textures(line, fd);
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
    char *line = NULL;
    fd = open(data->path,O_RDONLY);
    line = get_next_line(fd);
    line = go_pass_textures( line, fd);
    while (1)
    {
        if ((line == NULL) || (line[0] == '\n' && data->cub_map.map_row != 0))
            break;
        data->cub_map.map_row++;
        free(line);
        line = get_next_line(fd);
    }
    //printf("row:%d\n",data->cub_map.map_row);
}

int map_check(t_data *data)
{
    int fd;
    fd = open(data->path,O_RDONLY);
     
    map_row_count(data, fd);
    character_check(data);
    player_check(data);
    fill_map(data);
    map_close_check(data);
    close(fd);
    return 1;
   //multi_map_check(data, fd);
    //player_position();
}