/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:38:03 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/24 20:57:17 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

int max_row_lenght(t_data *data)
{
    size_t max_row;
    size_t tmp;
    int i;
    
    i = 0; 
    max_row = 0;
    tmp = 0;
    while(i < data->cub_map.map_row)
    {
        tmp = ft_strlen(data->cub_map.map[i]);
        if(tmp > max_row)
            max_row = tmp;    
        i++;
    }
    return(max_row);
}

int is_fill_line(char *line)
{
    int i;
    
    i = 0;
    if(line[i] == 32)
    {
        while(line[i] == 32)
        {
             if( line[i] == 'S' && line[i] == 'S' && 
                    line[i] == 'W' && line[i] == 'E' &&
                    line[i] == '0' && line[i] == '1')
                    return 0;
            i++;
        }
    }else
        return 1;
    return (1);
}
int is_there_char(char *line)
{
    int i = 0;

    if (!line)
        return 0;
    while (line[i])
    {
        if(line[i] == 'S' || line[i] == 'S' || 
                    line[i] == 'W' || line[i] == 'E' ||
                    line[i] == '0' || line[i] == '1')
            return 1;
        i++;
    }
    return 0;
}

int max_col_lenght(t_data *data)
{
    size_t max_col;
    size_t tmp;
    size_t i;
    size_t j;

    i = 0;
    max_col = 0;
    tmp = 0;
    j = 0;

    while (data->cub_map.map[j] && data->cub_map.map[j + 1] != NULL)
        j++;
    j--;
    while (j > 0)
    {
        if (is_there_char(data->cub_map.map[--j]))
            break ;
    }
    while (data->cub_map.map[i])
    {
        if (is_there_char(data->cub_map.map[i]))
            break ;
        i++;
    }

    max_col = j - i + 1;
    return (max_col);
}


void map_close_check(t_data *data)
{
    size_t max_row;
    size_t max_col;

    max_row = max_row_lenght(data);
    max_col = max_col_lenght(data);
    printf("max_col: %zu \n", max_col);

    //max_col_lenght(data);
     
    
}


// int find_height(t_data *data)
//  {
//     int height;
//     int tmp;
//     char *line;
//     int fd;
//     int i;
    
//     tmp = 0;
//     i = 0;
//     height = 0;
//     fd = open(data->path, O_RDONLY);
//     line = get_next_line(fd); 
//     line = go_pass_textures(line, fd);

//     while(line)
//     {
//         i = 0;
//         while(line[i]!= '\0')
//         {
//             if (line[i] && (line[i] != '\n'))
//                tmp++;
//             if(height < tmp)
//                 height = tmp;
//             tmp = 0;
//             i++;
//         }
//         free(line);
//         line = get_next_line(fd);
//     }
//     free(line);
//     close(fd);
//     printf("height%d:\n",height);
//     return(height);
//  }



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

