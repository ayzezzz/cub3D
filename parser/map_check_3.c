/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:56:19 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/27 15:37:35 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void player_loc(t_data *data)
{
    int i;
    int j;
    j = 0;
    i = 0;
    while(data->cub_map.map && data->cub_map.map[i]){
        j = 0;
        while( data->cub_map.map[i] && data->cub_map.map[i][j]){
            if(data->cub_map.map[i][j] == 'N' || data->cub_map.map[i][j] == 'S' || data->cub_map.map[i][j] == 'E' || data->cub_map.map[i][j] == 'W'){
                data->player.p_x = j + 0.5;
                data->player.p_y = i + 0.5;
                data->player.p_dir = data->cub_map.map[i][j];
            }
            j++;
        }
        i++;
    }
    
}
void flood_fill(t_data *data, int x, int y)
{
    if (data->cub_map.b_map[y][x] == 'B' || data->cub_map.b_map[y][x] == '*')
        return;
    data->cub_map.b_map[y][x] = '*';

//	if (data->cub_map.b_map[x + 1][y] != '*')
		flood_fill(data, x + 1, y);
//	if (data->cub_map.b_map[x - 1][y] != '*')
		flood_fill(data, x - 1, y);
//	if (data->cub_map.b_map[x][y + 1] != '*')
		flood_fill(data, x, y + 1);
//	if (data->cub_map.b_map[x][y - 1] != '*')
		flood_fill(data, x, y - 1);
}
 
void flood_fill_check(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;

    flood_fill(data, data->player.p_x, data->player.p_y);
    while(data->cub_map.b_map[i])
    {
        j = 0;
        while(data->cub_map.b_map[i][j])
        {
            if(data->cub_map.b_map[i][j] == '1' || data->cub_map.b_map[i][j] == '0' || 
            data->cub_map.b_map[i][j] == 'N' || data->cub_map.b_map[i][j] == 'S' || 
            data->cub_map.b_map[i][j] == 'W' || data->cub_map.b_map[i][j] == 'E')
            {
                free_data(data);
                error_message("Multi map! 🥺\n");
            }
            j++;       
        }
        i++;
    }
}
