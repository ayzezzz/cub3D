/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:39:17 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/22 20:23:10 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static int is_open_file(char *path)
{
    int fd;
    int i;
    i = 0;
    printf("file:%s\n",path);
    fd = open(path,O_RDONLY);
    if(fd < 0)
    {
        close(fd);
        return 0;
    }
    close(fd);
    return 1;
}

static int xpm_loop(t_data *data,char *path)
{
    size_t i ;
    i = 0;
    
    i = ft_strlen(path) -1;
    if(path[i] == 'm' && path[i - 1] == 'p' && path[i - 2] == 'x' && path[i - 3] == '.')
    {
        if(!is_open_file(data->textures.no) || !is_open_file(data->textures.so) || !is_open_file(data->textures.ea) || !is_open_file(data->textures.we)) 
        {
                textures_free(data);
                free(data);
                return  error_message("unopenable xpm extension 🥺\n"),0;
        }else
            return 1;
    }
    else
    {
            textures_free(data);
            free(data);
            return error_message("File does not exist or is not readable 🥺\n"),0;
    }
    
}

int is_xpm_file(t_data *data)
{
    if( !xpm_loop(data,data->textures.no) || !xpm_loop(data,data->textures.so) ||
   !xpm_loop(data,data->textures.ea) || !xpm_loop(data,data->textures.we))
        return 0;
    return 1;
}


char *find_texture_path(char *clean_str)
{
    int i = 0;
    int start ;
    start = 0;
    while(clean_str[i] && clean_str[i] == 32)
        i++;
    if(clean_str[i] != '.' && (clean_str[i + 1] &&  clean_str[i + 1] != '/'))
            return error_message("invalid texture character"),NULL;
    else
    {
    i = 0;
    while(clean_str[i])
    {
        
        if(clean_str[i] == '.' && (clean_str[i + 1] &&  clean_str[i + 1] == '/' ))
        {
            start = i ;
            while(clean_str[i] && clean_str[i] != 32)
                i++;
            return  ft_substr(clean_str,start,i); 
        }            
        if(clean_str[i])
            i++;
    }    
    }
    return NULL;
}

