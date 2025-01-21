/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:53:49 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/21 17:02:10 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

int pass_texture(t_data *data, char *line)
{
    (void)data;
   if (line[0] == 'N' || line[0] == 'S' || 
        line[0] == 'W' || line[0] == 'E' || line[0] == 'F' ||
        line[0] == 'C' || line[0] == '\n')
        return(1);
    return(0);

}

// void fill_map(t_data *data)
// {
    
// }

void multi_map_check(int fd)
{
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (line[0] != '\n')
        {   
            error_message("Multi map error 🥺\n");
            free(line);
            close(fd);
            break;
        }
        free(line); 
    }
    while(1)
    {
        if((line = get_next_line(fd)) == NULL)
            break;
    }
    close(fd);
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
    printf("line2: %s\n", line);

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
                error_message("Unvalid character 🥺\n");
                free(line);
                close(fd);
                break;
            }
            i++;
        }
        free(line);
        line = get_next_line(fd);
    }
   close(fd);
}

int map_check(t_data *data)
{
    int fd;
    int flag=0;
    char *line;

    fd = open(data->path,O_RDONLY);
    
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
        flag = 1;
        free(line);
    }
    free(line);
    multi_map_check(fd);
    character_check(data);
    //close(fd);
    printf("raw: %d", data->map.map_row);
    exit(1);
    return 0;
    // wall_check();
    // multi_map_check();
    // player_check();  wrong character 1 0 ' ' S N W E F C
    // player_count();
    // blank_check();
}