/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:53:49 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/23 19:14:50 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

// void multi_map_check(t_data *data, int fd)
// {
//     char *line;
//     int i;
//     i = 0;
//     line = get_next_line(fd);
//     line = go_pass_textures(data,line,fd);
//     while (i < data->map.map_row)
//     {
//         i++;
//         free(line); 
//         line = get_next_line(fd);

//     }
//     if (line && !ft_strchr(line,'0') && !ft_strchr(line,'1'))
//         {   
//             printf("line %s\n", line);
//             map_free(data, line, fd);
//             error_message("Multi map error! 🥺\n");
//         }
//     go_gnl_last(fd, line);
//     close(fd);
// }

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
    char *line = NULL;
    fd = open(data->path,O_RDONLY);
    line = get_next_line(fd);
    line = go_pass_textures(data, line, fd);
    while (1)
    {
        if ((line == NULL) || (line[0] == '\n' && data->map.map_row != 0))
            break;
        data->map.map_row++;
        free(line);
        line = get_next_line(fd);
    }
   // printf("row:%d:\n",data->map.map_row);
  
}
// int map_check(t_data *data)
// {
//     int fd;
//     int flag=0;
//     char *line;

//     fd = open(data->path,O_RDONLY);
    
//     while (1)
//     {
//         line = get_next_line(fd);
//         if (!line)
//             break;
//         if(pass_texture(data, line) && data->map.map_row == 0)
//         {
//             free(line);
//             continue;
//         }
//         if (line[0] == '\n' && data->map.map_row != 0)
//             break;
//         data->map.map_row++;
//         flag = 1;
//         free(line);
//     }
//     free(line);
//     multi_map_check(data, fd);
//     character_check(data);
//     player_check(data);
//     //player_position();
//     //close(fd);
//     return(0)
// }

int map_check(t_data *data)
{
    int fd;
    fd = open(data->path,O_RDONLY);
     
    map_row_count(data, fd);
   // multi_map_check(data, fd);
    character_check(data);
    player_check(data);
    //map_close_check(data);
    close(fd);
    return 0;
    //player_position();
    // fill_map();
}