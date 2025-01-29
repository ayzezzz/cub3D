/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:19:15 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/28 20:14:02 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void find_dir2(t_data *data)
{ 
    if(data->player.p_dir == 'E')
    {
      data->player.dir_x = 1;
      data->player.dir_y = 0;
      data->player.turn_angle = 0;
      data->player.plane_x = 0;
      data->player.plane_y = 0.66;
    }
    else if(data->player.p_dir == 'S')
    {
      data->player.dir_x = 0;
      data->player.dir_y = 1;
      data->player.turn_angle = 90;
      data->player.plane_x = 0.66;
      data->player.plane_y = 0;
    }
}

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
    else if(data->player.p_dir == 'W')
    {
      data->player.dir_x = -1;
      data->player.dir_y = 0;
      data->player.turn_angle = 180;
      data->player.plane_x = 0;
      data->player.plane_y = 0.66;
    }
    find_dir2(data);
}

void get_image(t_data *data)
{
    int width;
    int height;
    
    data->cub_mlx->ea =  mlx_xpm_file_to_image(data->cub_mlx->mlx, data->textures.ea, &width, &height);
    data->cub_mlx->so =  mlx_xpm_file_to_image(data->cub_mlx->mlx, data->textures.so, &width, &height);
    data->cub_mlx->we =  mlx_xpm_file_to_image(data->cub_mlx->mlx, data->textures.we, &width, &height);
    data->cub_mlx->no =  mlx_xpm_file_to_image(data->cub_mlx->mlx, data->textures.no, &width, &height);
}

void addr_img(t_data *data, void *img_ptr, int index)
{
  //özür dileriz :(
  //senden kaynaklı zannettik 
  //mlx_get_data_addr <3
  data->cub_mlx->te_img[index]->addr= (int *)mlx_get_data_addr(img_ptr, &data->cub_mlx->te_img[index]->bpp, &data->cub_mlx->te_img[index]->size_line, &data->cub_mlx->te_img[index]->endian);
  printf("%p\n", data->cub_mlx->te_img[index]->addr);
}

void set_addr_img(t_data *data)
{
  int i;

  i = 0;
  data->cub_mlx->te_img = malloc(4 * sizeof(t_img *));
  while (i < 4)
    data->cub_mlx->te_img[i++] = malloc(1 * sizeof(t_img));
  addr_img(data,data->cub_mlx->no,NO);
  addr_img(data,data->cub_mlx->so,SO);
  addr_img(data,data->cub_mlx->we,WE);
  addr_img(data,data->cub_mlx->ea,EA);
}

void game_start(t_data *data)
{
  data->cub_mlx = malloc(sizeof(t_mlx));
  data->cub_mlx->mlx =  mlx_init();
  data->cub_mlx->window = mlx_new_window(data->cub_mlx->mlx,s_width,s_height,"cub3D");
  data->cub_mlx->img = mlx_new_image(data->cub_mlx->mlx, s_width, s_height);
  data->cub_mlx->addr = (int *)mlx_get_data_addr(data->cub_mlx->img, &data->cub_mlx->bpp, &data->cub_mlx->size_line, &data->cub_mlx->endian);
  get_image(data);
  set_addr_img(data);
  mlx_loop(data->cub_mlx->mlx);   
}

void cub_game(t_data *data)
{
  game_start(data);
  find_dir(data);     
}