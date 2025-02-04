/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:12:59 by zayaz             #+#    #+#             */
/*   Updated: 2025/02/04 17:14:19 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static int check_above_boundary(t_data *data)
{
    int i = data->player.p_b_y;

    while (i >= 0)
    {
        if (data->cub_map.b_map[i][data->player.p_b_x] == '1')
            return 1;
        i--;
    }
    return 0;
}

static int check_down_boundary(t_data *data)
{
    int i = data->player.p_b_y + 1;

    while (i < data->cub_map.b_col)
    {
        if (data->cub_map.b_map[i][data->player.p_b_x] == '1')
            return 1;
        i++;
    }
    return 0;
}

void check_vertical_boundaries(t_data *data)
{
    int close_above = check_above_boundary(data);
    int close_down = check_down_boundary(data);

    if (close_above != 1 || close_down != 1)
    {
        free_data(data);
        error_message("Map is not closed! 🥺\n");
    }
}
