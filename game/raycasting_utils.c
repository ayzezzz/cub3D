/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:47:55 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/03 18:43:22 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void set_pixel(t_data *data, int line_h, int side)
{
    if (side == 0)
        data->rayc->hit_x = data->player.p_y + data->rayc->wall_dist * data->rayc->ray_dir_y;
    else
        data->rayc->hit_x = data->player.p_x + data->rayc->wall_dist * data->rayc->ray_dir_x;
    data->rayc->hit_x -= floor(data->rayc->hit_x);
    data->rayc->text_x = (int)(data->rayc->hit_x * 64);
    data->rayc->per_pix = 1.0 * 64 / line_h;
    data->rayc->tex_y_next = (data->rayc->wall_start - s_height / 2 + line_h / 2) * data->rayc->per_pix;
}

void draw_textured_column(t_data *data, int side, int col)
{
    int i;
    int text_i;
    int color;

    i = data->rayc->wall_start;
    color = 0;

    while (i < data->rayc->wall_end)
    {

        data->rayc->text_y = (int)data->rayc->tex_y_next & (data->cub_mlx->map_size - 1);
        data->rayc->tex_y_next += data->rayc->per_pix;
        text_i = data->rayc->text_x + data->cub_mlx->map_size * data->rayc->text_y;
        if (data->rayc->ray_dir_x > 0 && side == 0)
            color = data->cub_mlx->te_img[WE]->addr[text_i];
        else if (data->rayc->ray_dir_x < 0 && side == 0)
            color = data->cub_mlx->te_img[EA]->addr[text_i];
        else if (data->rayc->ray_dir_y > 0 && side == 1)
            color = data->cub_mlx->te_img[NO]->addr[text_i];
        else if (data->rayc->ray_dir_y < 0 && side == 1)
            color = data->cub_mlx->te_img[SO]->addr[text_i];
        data->cub_mlx->addr[i * s_width + col] = color;
        i++;
    }
}
