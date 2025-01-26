/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:56:19 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/26 19:27:24 by itulgar          ###   ########.fr       */
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
        while( data->cub_map.map[x] && data->cub_map.map[x][y]){
            if(data->cub_map.map[x][y] == 'N' || data->cub_map.map[x][y] == 'S' || data->cub_map.map[x][y] == 'E' || data->cub_map.map[x][y] == 'W'){
                data->player.p_x = x;
                data->player.p_y = y;
            }
            y++;
        }
        x++;
    }
    
}
void flood_fill(t_data *data, int x, int y)
{
    if (data->cub_map.b_map[x][y] == 'B' || data->cub_map.b_map[x][y] == '*')
        return;
    data->cub_map.b_map[x][y] = '*';

	if (data->cub_map.b_map[x + 1][y] != '*')
		flood_fill(data, x + 1, y);
	if ( data->cub_map.b_map[x - 1][y] != '*')
		flood_fill(data, x - 1, y);
	if (data->cub_map.b_map[x][y + 1] != '*')
		flood_fill(data, x, y + 1);
	if (data->cub_map.b_map[x][y - 1] != '*')
		flood_fill(data, x, y - 1);
}
 
void flood_fill_check(t_data *data)
{
    int x;
    int y;

    x = 0;
    y = 0;

    flood_fill(data, data->player.p_x, data->player.p_y);
    int i;
     i = 0;
    while(data->cub_map.b_map[i]){
        printf("b_map: %s\n",data->cub_map.b_map[i]);
        i++;
   }
    while(data->cub_map.b_map[y])
    {
        x = 0;
        while(data->cub_map.b_map[y][x])
        {
            if(data->cub_map.b_map[y][x] == '1' || data->cub_map.b_map[y][x] == '0' || 
            data->cub_map.b_map[y][x] == 'N' || data->cub_map.b_map[y][x] == 'S' || 
            data->cub_map.b_map[y][x] == 'W' || data->cub_map.b_map[y][x] == 'E')
            {
                free_data(data);
                error_message("Multi map! 🥺\n");
            }
            x++;       
        }
        y++;
    }
}
