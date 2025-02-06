/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:12:51 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/05 19:50:06 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void	get_image(t_data *data)
{
	data->cub_mlx->ea = mlx_xpm_file_to_image(data->cub_mlx->mlx,
			data->textures.ea, &data->cub_mlx->map_size,
			&data->cub_mlx->map_size);
	data->cub_mlx->so = mlx_xpm_file_to_image(data->cub_mlx->mlx,
			data->textures.so, &data->cub_mlx->map_size,
			&data->cub_mlx->map_size);
	data->cub_mlx->we = mlx_xpm_file_to_image(data->cub_mlx->mlx,
			data->textures.we, &data->cub_mlx->map_size,
			&data->cub_mlx->map_size);
	data->cub_mlx->no = mlx_xpm_file_to_image(data->cub_mlx->mlx,
			data->textures.no, &data->cub_mlx->map_size,
			&data->cub_mlx->map_size);
}

void	addr_img(t_data *data, void *img_ptr, int index)
{
	data->cub_mlx->te_img[index]->addr = (int *)mlx_get_data_addr(img_ptr,
			&data->cub_mlx->te_img[index]->bpp,
			&data->cub_mlx->te_img[index]->size_line,
			&data->cub_mlx->te_img[index]->endian);
}

void	set_addr_img(t_data *data)
{
	int	i;

	i = 0;
	data->cub_mlx->te_img = malloc(4 * sizeof(t_img *));
	while (i < 4)
		data->cub_mlx->te_img[i++] = malloc(1 * sizeof(t_img));
	addr_img(data, data->cub_mlx->no, NO);
	addr_img(data, data->cub_mlx->so, SO);
	addr_img(data, data->cub_mlx->we, WE);
	addr_img(data, data->cub_mlx->ea, EA);
}

void	image_init(t_data *data)
{
	data->cub_mlx->img = mlx_new_image(data->cub_mlx->mlx, S_WIDTH, S_HEIGHT);
	data->cub_mlx->addr = (int *)mlx_get_data_addr(data->cub_mlx->img,
			&data->cub_mlx->bpp, &data->cub_mlx->size_line,
			&data->cub_mlx->endian);
	get_image(data);
	set_addr_img(data);
}
