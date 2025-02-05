/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:50:56 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/05 19:41:14 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void	error_message(char *str)
{
	printf("Error\n%s", str);
	exit(1);
}

void	textures_free(t_data *data)
{
	double_str_free(data->textures.f);
	double_str_free(data->textures.c);
	free(data->textures.no);
	free(data->textures.we);
	free(data->textures.ea);
	free(data->textures.so);
}

void	double_str_free(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

void	free_image(t_mlx *cub_mlx)
{
	int	i;

	i = 0;
	mlx_destroy_image(cub_mlx->mlx, cub_mlx->img);
	mlx_destroy_image(cub_mlx->mlx, cub_mlx->ea);
	mlx_destroy_image(cub_mlx->mlx, cub_mlx->so);
	mlx_destroy_image(cub_mlx->mlx, cub_mlx->we);
	mlx_destroy_image(cub_mlx->mlx, cub_mlx->no);
	mlx_destroy_window(cub_mlx->mlx, cub_mlx->window);
	mlx_destroy_display(cub_mlx->mlx);
	free(cub_mlx->mlx);
	while (i < 4)
		free(cub_mlx->te_img[i++]);
	free(cub_mlx->te_img);
}

int	close_window(t_data *data)
{
	free_image(data->cub_mlx);
	free(data->cub_mlx);
	free_data(data);
	printf("GAME OVER BY BY 😎\n");
	exit(0);
}
