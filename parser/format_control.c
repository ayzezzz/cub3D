/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:39:17 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/24 12:12:17 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static int is_open_file(char *path)
{
    int fd;
    int i;
    i = 0;
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
        return error_message("Not with .xpm extension 🥺\n"),0;
    }
    
}

int is_xpm_file(t_data *data)
{
    if( !xpm_loop(data,data->textures.no) || !xpm_loop(data,data->textures.so) ||
   !xpm_loop(data,data->textures.ea) || !xpm_loop(data,data->textures.we))
        return 0;
    return 1;
}

static char *is_xpm_check(char **str,char *path)
{
    int i;
    int start;
    start = 0;
    i = 0;
    while(str[0][i])
    {
        if(((str[0][0] == '.' && (str[0][1] &&  str[0][1] == '/')) ||  (str[0][0] == '/')) && str[1] == NULL)
        {
            start = i ;
            while(str[0][i] && str[0][i] != 32)
                i++;
            path = ft_substr(str[0],start,i);
            double_str_free(str); 
            return  path;
        }            
        if(str[0][i])
            i++;
    }
    return path; 
}

char *find_texture_path(t_data *data,char *clean_str)
{
    char *path = NULL;
    char **str;

    str = ft_split(clean_str,32);
    if(((str[0][0] == '.' && (str[0][1] &&  str[0][1] == '/')) ||  (str[0][0] == '/')) && str[1] == NULL)
        path = is_xpm_check(str,path);
    if(!path)
    {
        double_str_free(str);
        textures_free(data);
        free(data);
        return error_message("invalid character 🥺\n"),NULL;
    }
    return path;
}

