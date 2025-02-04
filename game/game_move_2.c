/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:46:39 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/03 19:20:59 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void turn_right(t_data *data)
{
   double before_dir_x;
   double before_plane_x;

   before_dir_x = data->player.dir_x;
   before_plane_x = data->player.plane_x;

   data->player.dir_x = before_dir_x * cos(data->key.dir_speed) - data->player.dir_y * sin(data->key.dir_speed);
   data->player.dir_y = before_dir_x * sin(data->key.dir_speed) + data->player.dir_y * cos(data->key.dir_speed);
   data->player.plane_x = before_plane_x * cos(data->key.dir_speed) - data->player.plane_y * sin(data->key.dir_speed);
   data->player.plane_y = before_plane_x * sin(data->key.dir_speed) + data->player.plane_y * cos(data->key.dir_speed);
}

void turn_left(t_data *data)
{
   double before_dir_x;
   double before_plane_x;

   before_dir_x = data->player.dir_x;
   before_plane_x = data->player.plane_x;
   
   data->player.dir_x = before_dir_x * cos(-data->key.dir_speed) - data->player.dir_y * sin(-data->key.dir_speed);
   data->player.dir_y = before_dir_x * sin(-data->key.dir_speed) + data->player.dir_y * cos(-data->key.dir_speed);
   data->player.plane_x = before_plane_x * cos(-data->key.dir_speed) - data->player.plane_y * sin(-data->key.dir_speed);
   data->player.plane_y = before_plane_x * sin(-data->key.dir_speed) + data->player.plane_y * cos(-data->key.dir_speed);    
}
