/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_control_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:39:54 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/24 17:19:20 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static int is_two_comma(char *clean_str)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while(clean_str[i]){
        if(clean_str[i] == ',')
            count++;
        i++;
    }
    if(count != 2)
        return 0;
    return 1;
}

static int is_invalid_character(char *clean_str)
{
    int i;
    i = 0;
    while(clean_str[i])
    {
        if(!(clean_str[i] >='0' && clean_str[i] <='9') && clean_str[i] != 32 && clean_str[i] != ',')
            return 0;
        i++;
    }
    return 1;
}


void find_color_num(t_data *data,char* clean_str)
{
    char **int_str;
    int i;
    int num;
    char *tmp;
    i = 0;
    if(!is_two_comma(clean_str) || !is_invalid_character(clean_str)){
        textures_free(data);
        free(data);
        error_message("Color format error 🥺\n");
    }
    int_str = ft_split(clean_str,',');
    
    while(i < 3){
        num = ft_atoi(int_str[i]);
        tmp = ft_strtrim(int_str[i]," \n");
        if (ft_strlen(tmp) > 3 || !(num >= 0  && num <= 255))
            error_message("Must be in 0- 255 format 🥺\n");
        free(tmp);
        i++;
    } 
    double_str_free(int_str);
    
}
