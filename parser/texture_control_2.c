/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_control_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:39:54 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/05 19:01:49 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"


int texture_error(t_data *data,char *clean_str)
{
    int set;
    if((set = set_texture(data,clean_str)))
        {  
            if(set == 2)
              return printf("Color format error! 🥺\n"),0;
            else if (set == 1)
               return  printf("Invalid path error! 🥺\n"),0;
         
        }
    return 1;
}


static int is_two_comma(char *clean_str)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (clean_str[i])
    {
        if (clean_str[i] == ',')
            count++;
        i++;
    }
    if (count != 2)
        return 0;
    return 1;
}

static int is_invalid_character(char **int_str)
{
    int i;
    char *tmp;
    int j;
    j = 0;
    i = 0;
    while (int_str[i])
    {
        tmp = ft_strtrim(int_str[i]," \n");
        j = 0;
        while(tmp[j]){
            if(!(tmp[j] >= '0' && tmp[j] <= '9') || (tmp[0] == '0' && tmp[1] && ft_isdigit(tmp[1])))
                return free(tmp),0;
            j++;
        }
        free(tmp);
        i++;
    }
    return (1);
}

static int  comma_in_fill(char **int_str){
    int i;
    i = 0;
    while(int_str[i])
        i++;
    if(i != 3)
       return 0;
    return 1;
}

char **find_color_num(char* clean_str)
{
    char **int_str;
    int i;
    int num;
    char *tmp;
    i = 0;
    int_str = ft_split(clean_str,',');
    if(!is_two_comma(clean_str) || !is_invalid_character(int_str))
        return double_str_free(int_str),NULL;
    if(!comma_in_fill(int_str))
        return double_str_free(int_str),NULL;

    while(i < 3){
        tmp = ft_strtrim(int_str[i]," \n");
        num = ft_atoi(tmp);
        if (ft_strlen(tmp) > 3 || (ft_strlen(tmp) == 0) || ft_strchr(tmp,32) || !(num >= 0  && num <= 255))
        {
            double_str_free(int_str);
            free(tmp);
            return NULL;
        }
        free(tmp);
        i++;
    } 
    return int_str;
}
