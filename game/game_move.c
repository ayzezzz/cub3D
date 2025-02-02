/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:41:20 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/02 19:25:49 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void move_up(t_data *data)
{
    double x;
    double y;
    
    x = data->player.p_x + data->player.dir_x * data->key.move_speed;
    y = data->player.p_y + data->player.dir_y * data->key.move_speed;
    if(data->cub_map.map[(int)data->player.p_y][(int)x] != '1')
        data->player.p_x = x;
    if(data->cub_map.map[(int)y][(int)data->player.p_x] != '1')
        data->player.p_y = y; 
}

void move_down(t_data *data)
{
    double x;
    double y;
    
    x = data->player.p_x - data->player.dir_x * data->key.move_speed;
    y = data->player.p_y - data->player.dir_y * data->key.move_speed;
    if(data->cub_map.map[(int)data->player.p_y][(int)x] != '1')
        data->player.p_x = x;
    if(data->cub_map.map[(int)y][(int)data->player.p_x] != '1')
        data->player.p_y = y; 

}
void move_left(t_data *data)
{
    double x;
    double y;
    
    x = data->player.p_x - data->player.plane_x * data->key.move_speed;
    y = data->player.p_y - data->player.plane_y * data->key.move_speed;
    if(data->cub_map.map[(int)data->player.p_y][(int)x] != '1')
        data->player.p_x = x;
    if(data->cub_map.map[(int)y][(int)data->player.p_x] != '1')
        data->player.p_y = y; 

}

void move_right(t_data *data)
{
    double x;
    double y;
    
    x = data->player.p_x + data->player.plane_x * data->key.move_speed;
    y = data->player.p_y + data->player.plane_y * data->key.move_speed;
    if(data->cub_map.map[(int)data->player.p_y][(int)x] != '1')
        data->player.p_x = x;
    if(data->cub_map.map[(int)y][(int)data->player.p_x] != '1')
        data->player.p_y = y; 
}


void call_move(t_data *data)
{
    if(data->key.w)
        move_up(data);
    if(data->key.a)
        move_left(data);
    if(data->key.d)
        move_right(data);
    if(data->key.s)
        move_down(data);
    if(data->key.left_p)
        turn_left(data);
    if(data->key.right_p)
        turn_right(data);
}
