/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:12:59 by zayaz             #+#    #+#             */
/*   Updated: 2025/02/05 19:20:23 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

int	check_above_boundary(t_data *data)
{
	int	i;

	i = data->player.p_b_y;
	while (i >= 0)
	{
		if (data->cub_map.b_map[i][data->player.p_b_x] == '1')
			return (1);
		i--;
	}
	return (0);
}

int	check_down_boundary(t_data *data)
{
	int	i;

	i = data->player.p_b_y + 1;
	while (i < data->cub_map.b_col)
	{
		if (data->cub_map.b_map[i][data->player.p_b_x] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_left_boundary(t_data *data)
{
	int	j;

	j = data->player.p_b_x;
	while (j >= 0)
	{
		if (data->cub_map.b_map[data->player.p_b_y][j] == '1')
			return (1);
		j--;
	}
	return (0);
}

int	check_right_boundary(t_data *data)
{
	int	j;

	j = data->player.p_b_x + 1;
	while (j < data->cub_map.b_row)
	{
		if (data->cub_map.b_map[data->player.p_b_y][j] == '1')
			return (1);
		j++;
	}
	return (0);
}

void	fill_map_free(t_data *data)
{
	if (data->cub_map.b_map)
		double_str_free(data->cub_map.b_map);
	if (data->cub_map.map)
		double_str_free(data->cub_map.map);
	if (data->cub_map.cpymap)
		double_str_free(data->cub_map.cpymap);
	textures_free(data);
	if (data->rayc)
		free(data->rayc);
	free(data);
}
