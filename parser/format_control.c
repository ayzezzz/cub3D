/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:39:17 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/22 14:05:46 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

// int is_xpm_file(t_data *data){
//     //xpm uzantılı mı 
//     //açılıyor mu 
//     size_t i;
//     i = ft_strlen()
// }

char *find_texture_path(char *clean_str)
{
      int i = 0;
      int start ;
      start = 0;

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
    return NULL;
}

