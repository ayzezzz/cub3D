/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:56:19 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/05 15:13:13 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"


static void check_player_boundary(t_data *data)
{
    int close_above = check_above_boundary(data);
    int close_down = check_down_boundary(data);
    int close_left = check_left_boundary(data);
    int close_right = check_right_boundary(data);

    if (close_above != 1 || close_down != 1 || close_left != 1 || close_right != 1)
    {
        fill_map_free(data);
        error_message("Map is not closed! 🥺\n");
    }
}

static void player_b_loc(t_data *data)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (data->cub_map.b_map && data->cub_map.b_map[i])
    {
        j = 0;
        while (data->cub_map.b_map[i] && data->cub_map.b_map[i][j])
        {
            if (data->cub_map.b_map[i][j] == 'N' || data->cub_map.b_map[i][j] == 'S' || data->cub_map.b_map[i][j] == 'E' || data->cub_map.b_map[i][j] == 'W')
            {
                data->player.p_b_x = j;
                data->player.p_b_y = i;
            }
            j++;
        }
        i++;
    }
    check_player_boundary(data);
}

static void flood_fill(t_data *data, int x, int y)
{
    if (data->cub_map.b_map[y][x] == 'B' || data->cub_map.b_map[y][x] == '*')
        return;
    data->cub_map.b_map[y][x] = '*';

    flood_fill(data, x + 1, y);
    flood_fill(data, x - 1, y);
    flood_fill(data, x, y + 1);
    flood_fill(data, x, y - 1);
}

void flood_fill_check(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    player_b_loc(data);
    flood_fill(data, data->player.p_b_x, data->player.p_b_y);
    while (data->cub_map.b_map[i])
    {
        j = 0;
        while (data->cub_map.b_map[i][j])
        {
            if (data->cub_map.b_map[i][j] == '1' || data->cub_map.b_map[i][j] == '0' ||
                data->cub_map.b_map[i][j] == 'N' || data->cub_map.b_map[i][j] == 'S' ||
                data->cub_map.b_map[i][j] == 'W' || data->cub_map.b_map[i][j] == 'E')
            {
                fill_map_free(data);
                error_message("Multi map! 🥺\n");
            }
            j++;
        }
        i++;
    }
}
