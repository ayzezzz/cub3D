/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:31:53 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/23 14:40:53 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

int cub_check(t_data *data)
{
    if(!is_textures_top(data)) 
        return 0;
    if(!texture_count_check(data)) 
        return 0;
    if(!is_xpm_file(data))
        return 0;
     if(!map_check(data)) 
        return 0;
    return(1);
}
