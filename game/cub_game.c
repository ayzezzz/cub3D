/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:19:15 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/30 16:59:09 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void find_dir2(t_data *data)
{ 
  if(data->player.p_dir == 'E')
  {
    data->player.dir_x = 1;
    data->player.dir_y = 0;
    data->player.plane_x = 0;
    data->player.plane_y = 0.66;
  }
  else if(data->player.p_dir == 'W')
  {
    data->player.dir_x = -1;
    data->player.dir_y = 0;
    data->player.plane_x = 0;
    data->player.plane_y = 0.66;
  }
}

void find_dir(t_data *data)
{
  if(data->player.p_dir == 'N')
  {
    data->player.dir_x = 0;
    data->player.dir_y = -1;
    data->player.plane_x = 0.66;
    data->player.plane_y = 0;
  }
  else if(data->player.p_dir == 'S')
  {
    data->player.dir_x = 0;
    data->player.dir_y = 1;
    data->player.plane_x = -0.66;
    data->player.plane_y = 0;
  }
  else
    find_dir2(data);
}

void game_start(t_data *data)
{
  data->cub_mlx = malloc(sizeof(t_mlx));
  data->cub_mlx->mlx =  mlx_init();
  data->cub_mlx->window = mlx_new_window(data->cub_mlx->mlx,s_width,s_height,"cub3D");
  image_init(data);
  mlx_loop_hook(data->cub_mlx->mlx,image_loop,data);
  mlx_key_hook(data->cub_mlx->window,key_press,data);
  mlx_hook(data->cub_mlx->window,17,0,close_window,data);
  mlx_loop(data->cub_mlx->mlx);
}

void cub_game(t_data *data)
{
  find_dir(data);
  game_start(data);
}
