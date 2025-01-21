/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:31:53 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/21 17:05:07 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"


int is_fill_textures(t_data *data){
    int i=0;
    while(data->textures.check_list[i]){
        if(data->textures.check_list[i] == 0){
         free(data);
         return error_message("invalid textures count 🥺\n"),0;   
        } 
        i++;
    }
    return 1;
}

int texture_count_check(t_data *data){

   char *str;
   char *clean_str;
   int fd ;
   int i;
   
   fd=open(data->path,O_RDONLY);
   i = 0;
   while (str=get_next_line(fd))
    {
        clean_str = ft_strtrim(str,32);
        if(ft_strncmp(clean_str,"NO",ft_strlen(clean_str))){
            
            data->textures.check_list[NO]=1;
        } 
        else if (ft_strncmp(clean_str,"SO",ft_strlen(clean_str))){
             data->textures.check_list[SO]=1;
        }
        else if(ft_strncmp(clean_str,"WE",ft_strlen(clean_str))){
             data->textures.check_list[WE]=1;
        }
        else if (ft_strncmp(clean_str,"EA",ft_strlen(clean_str))){
             data->textures.check_list[EA]=1;
        }
        else if(ft_strncmp(clean_str,"F",ft_strlen(clean_str))){
             data->textures.check_list[F]=1;
        }
        else if(ft_strncmp(clean_str,"C",ft_strlen(clean_str))){
             data->textures.check_list[C]=1;
        }
        i++;
    }
    if(!is_fil_textures(data))
        return 0;
    close(fd);
}

int cub_check(t_data *data)
{
    if(!texture_count_check(data)) 
        return 0;
     if(!map_check(data)) 
        return 0;
    return(1);
}
