/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:19:15 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/27 19:32:47 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void find_dir(t_data *data)
{
    if(data->player.p_dir == 'N')
    {
        data->player.dir_x = 0;
        data->player.dir_y = -1;
        data->player.turn_angle = 270;
        data->player.plane_x = 0.66;
        data->player.plane_y = 0;
    }
      else if(data->player.p_dir == 'W'){
        data->player.dir_x = -1;
        data->player.dir_y = 0;
        data->player.turn_angle = 180;
        data->player.plane_x = 0;
        data->player.plane_y = 0.66;
      }
      else if(data->player.p_dir == 'E'){
        data->player.dir_x = 1;
        data->player.dir_y = 0;
        data->player.turn_angle = 0;
        data->player.plane_x = 0;
        data->player.plane_y = 0.66;
      }
      else if(data->player.p_dir == 'S'){
        data->player.dir_x = 0;
        data->player.dir_y = 1;
        data->player.turn_angle = 90;
        data->player.plane_x = 0.66;
        data->player.plane_y = 0;
      }
}

void get_image(t_data *data)
{
    int width;
    int height;
    
    data->cub_mlx.ea =  mlx_xpm_to_image(data->cub_mlx.mlx,&data->textures.ea,&width,&height);
    data->cub_mlx.so =  mlx_xpm_to_image(data->cub_mlx.mlx,&data->textures.so,&width,&height);
    data->cub_mlx.we =  mlx_xpm_to_image(data->cub_mlx.mlx,&data->textures.we,&width,&height);
    data->cub_mlx.no =  mlx_xpm_to_image(data->cub_mlx.mlx,&data->textures.no,&width,&height);
    
}

void game_start(t_data *data)
{
   data->cub_mlx.mlx =  mlx_init();
   data->cub_mlx.window = mlx_new_window(data->cub_mlx.mlx,s_width,s_height,"cub3D");
   data->cub_mlx.img = mlx_new_image(data->cub_mlx.mlx, s_width, s_height);
   
   get_image(data);
   mlx_loop(data->cub_mlx.mlx);
    
}

void cub_game(t_data *data)
{
    game_start(data);
    find_dir(data);
  
        
}