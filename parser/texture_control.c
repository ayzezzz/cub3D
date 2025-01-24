/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:00:45 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/24 17:30:17 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static void init_check_list(t_data *data)
{
    int i;
    i = 0;
    while(i < 6)
        data->textures.check_list[i++] = 0;
}

static int is_fill_textures(t_data *data)
{
    int i;
    i = 0;
    while(i < 6)
    {
        if(data->textures.check_list[i] == 0 || data->textures.check_list[i] > 1 )
        {
           textures_free(data);
           free(data);
           return 0;   
        } 
        i++;
    }
    return 1;
}

static void set_texture(t_data *data,char * clean_str)
{
    if(clean_str[0] == 'N' && clean_str[1] == 'O' && clean_str[2] == ' '){
        data->textures.check_list[NO]+= 1;
        if(data->textures.check_list[NO] == 1)
            data->textures.no  = find_texture_path(data,clean_str + 3);
    }
        else if (clean_str[0] == 'S' && clean_str[1] == 'O' && clean_str[2] == ' '){
             data->textures.check_list[SO]+= 1;
                if(data->textures.check_list[SO] == 1)
            data->textures.so  = find_texture_path(data,clean_str + 3);
        }
        else if(clean_str[0] == 'W' && clean_str[1] == 'E' && clean_str[2] == ' '){
             data->textures.check_list[WE]+= 1;
               if(data->textures.check_list[WE] == 1)
            data->textures.we  = find_texture_path(data,clean_str + 3);   
        }
        else if (clean_str[0] == 'E' && clean_str[1] == 'A' && clean_str[2] == ' '){
             data->textures.check_list[EA]+= 1;
            if(data->textures.check_list[EA] == 1)
            data->textures.ea  = find_texture_path(data,clean_str + 3);
        }
        else if((clean_str[0] == 'F' && clean_str[1] == ' ')){
            data->textures.check_list[F] += 1;
            find_color_num(data,clean_str + 3);
        }
        else if((clean_str[0] == 'C' && clean_str[1]  ==  ' ')){
            data->textures.check_list[C] += 1;
            find_color_num(data,clean_str + 3);
        }
}

static int texture_loop(t_data *data, int *i, char*str, int fd)
{
    while(*i < data->cub_map.map_row)
    {
        free(str);
        str = get_next_line(fd);
        (*i)++;
    }
    if(!is_fill_textures(data))
        return error_message("Texture wrong format 🥺\n"),0; 
    return 1;
}


int texture_count_check(t_data *data)
{

   char *str;
   char *clean_str;
   int fd ;
   int i;
   i = 0;
   init_check_list(data);
   fd=open(data->path,O_RDONLY);
   while ((str = get_next_line(fd)))
    {
        clean_str = ft_strtrim(str," \n");
        if((clean_str[0] == '0' || clean_str[0] == '1') &&  !texture_loop(data,&i,str,fd))
            return 0;
        set_texture(data,clean_str);
        free(str);
        free(clean_str);
    }
    close(fd);
    if(!is_fill_textures(data))
        return error_message("Invalid textures count 🥺\n"),0;
    return 1;
}
