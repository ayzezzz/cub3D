/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:39:17 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/21 19:18:52 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

// int is_xpm_file(t_data *data){
//     //xpm uzantılı mı 
//     //açılıyor mu 
//     size_t i;
//     i = ft_strlen()
// }

void find_texture_path(char *clean_str,char *textures)
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
            textures = ft_substr(clean_str,start,i); 
        }
        if(clean_str[i])
            i++;                 
    }
}

