/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:56:19 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/24 21:03:44 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void player_loc(t_data *data)
{
    int x;
    int y;
    y = 0;
    x = 0;
    while(data->cub_map.map && data->cub_map.map[x]){
        y = 0;
        while(data->cub_map.map[x][y]){
            if(data->cub_map.map[x][y] == 'N' || data->cub_map.map[x][y] == 'S' || data->cub_map.map[x][y] == 'E' || data->cub_map.map[x][y] == 'W'){
                data->player.p_x = x;
                data->player.p_y = y;
            }
            y++;
        }
        x++;
    }
}

// static void paint_map(t_data *data)

// // 1 veya f dışındakilere 0 varsa floodfill oyun oynanamaz demek

// int is_game_played(t_data *data)
// {
//     paint_map(data,data->player.p_x,data->player.p_y);
    
// }