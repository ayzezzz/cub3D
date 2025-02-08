/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:12:37 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/06 20:18:30 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static int	set_rgb(char **color_type)
{
	int	i;
	int	red;
	int	green;
	int	blue;

	red = ft_atoi(color_type[0]) << 16;
	green = ft_atoi(color_type[1]) << 8;
	blue = ft_atoi(color_type[2]);
	i = red | green | blue;
	return (i);
}

static void	horizon_line(t_data *data)
{
	int	i;
	int	j;
	int	f;
	int	c;

	j = 0;
	i = 0;
	f = set_rgb(data->textures.f);
	c = set_rgb(data->textures.c);
	while (i < S_HEIGHT)
	{
		j = 0;
		while (j < S_WIDTH)
		{
			if (i < S_HEIGHT / 2)
				data->cub_mlx->addr[(S_WIDTH * i) + j] = c;
			else
				data->cub_mlx->addr[(S_WIDTH * i) + j] = f;
			j++;
		}
		i++;
	}
}

int	image_loop(t_data *data)
{
	horizon_line(data);
	raycasting(data);
	mlx_put_image_to_window(data->cub_mlx->mlx, data->cub_mlx->window,
		data->cub_mlx->img, 0, 0);
	call_move(data);
	return (0);
}
