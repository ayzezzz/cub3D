/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:54:45 by zayaz             #+#    #+#             */
/*   Updated: 2025/02/04 19:54:47 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static void	set_variable(t_data *data, int i)
{
	data->rayc = (t_rayc *)ft_calloc(1, sizeof(t_rayc));
	data->rayc->camera_x = 2 * i / (double)S_WIDTH - 1;
	data->rayc->ray_dir_x = data->player.dir_x + data->player.plane_x
		* data->rayc->camera_x;
	data->rayc->ray_dir_y = data->player.dir_y + data->player.plane_y
		* data->rayc->camera_x;
	data->rayc->map_x = (int)data->player.p_x;
	data->rayc->map_y = (int)data->player.p_y;
	data->rayc->delta_x = fabs(1 / data->rayc->ray_dir_x);
	data->rayc->delta_y = fabs(1 / data->rayc->ray_dir_y);
}

static void	calculate_distance(t_data *data)
{
	if (data->rayc->ray_dir_x < 0)
	{
		data->rayc->side_x = (data->player.p_x - data->rayc->map_x)
			* data->rayc->delta_x;
		data->rayc->step_x = -1;
	}
	else
	{
		data->rayc->step_x = 1;
		data->rayc->side_x = (data->rayc->map_x + 1.0 - data->player.p_x)
			* data->rayc->delta_x;
	}
	if (data->rayc->ray_dir_y < 0)
	{
		data->rayc->side_y = (data->player.p_y - data->rayc->map_y)
			* data->rayc->delta_y;
		data->rayc->step_y = -1;
	}
	else
	{
		data->rayc->step_y = 1;
		data->rayc->side_y = (data->rayc->map_y + 1.0 - data->player.p_y)
			* data->rayc->delta_y;
	}
}

static int	dda_algorithm(t_data *data)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (data->rayc->side_x < data->rayc->side_y)
		{
			side = 0;
			data->rayc->side_x += data->rayc->delta_x;
			data->rayc->map_x += data->rayc->step_x;
		}
		else
		{
			side = 1;
			data->rayc->side_y += data->rayc->delta_y;
			data->rayc->map_y += data->rayc->step_y;
		}
		if (data->cub_map.map[data->rayc->map_y][data->rayc->map_x] == '1')
			hit = 1;
	}
	return (side);
}

void	draw_wall(t_data *data, int side, int col)
{
	int	line_h;

	line_h = (int)S_HEIGHT / data->rayc->wall_dist;
	data->rayc->wall_start = -line_h / 2 + S_HEIGHT / 2;
	if (data->rayc->wall_start < 0)
		data->rayc->wall_start = 0;
	data->rayc->wall_end = line_h / 2 + S_HEIGHT / 2;
	if (data->rayc->wall_end > S_HEIGHT)
		data->rayc->wall_end = S_HEIGHT;
	set_pixel(data, line_h, side);
	draw_textured_column(data, side, col);
}

void	raycasting(t_data *data)
{
	int	i;
	int	side;

	side = 0;
	i = 0;
	while (i < S_WIDTH)
	{
		set_variable(data, i);
		calculate_distance(data);
		side = dda_algorithm(data);
		if (side == 0)
			data->rayc->wall_dist = data->rayc->side_x - data->rayc->delta_x;
		else
			data->rayc->wall_dist = data->rayc->side_y - data->rayc->delta_y;
		draw_wall(data, side, i);
		free(data->rayc);
		i++;
	}
}
