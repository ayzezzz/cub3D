/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:12:37 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/30 14:32:22 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"


int set_rgb(char **color_type)
{  
    int i;
    i = (ft_atoi(color_type[0]) << 16) | (ft_atoi(color_type[1]) << 8) | ft_atoi(color_type[2]);
    return(i);
}

void horizon_line(t_data *data)
{
    int i;
    int j;
    int f;
    int c;
    j = 0;
    i = 0;
    f= set_rgb(data->textures.f);
    c = set_rgb(data->textures.c);

    while(i < s_height)
    {
        j = 0;
        while(j < s_width)
        {
            if(i < s_height / 2) 
                data->cub_mlx->addr[(s_width * i) + j] = c;
            else 
              data->cub_mlx->addr[(s_width * i) + j] = f;  
            j++;
        }
        i++;    
    }
   
}

int image_loop(t_data *data)
{
    horizon_line(data);
    raycasting(data);
   mlx_put_image_to_window(data->cub_mlx->mlx,data->cub_mlx->window,data->cub_mlx->img,0,0);
    return 0;
}