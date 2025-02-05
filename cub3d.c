/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:41:23 by zayaz             #+#    #+#             */
/*   Updated: 2025/02/05 20:02:10 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

static void	cub_game(t_data *data)
{
	find_dir(data);
	game_start(data);
}

static void	cub_check(t_data *data)
{
	texture_count_check(data);
	is_xpm_file(data);
	map_check(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		error_message("Invalid Argumanet!!! 🥺\n");
	file_path_control(argv[1]);
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	data->path = argv[1];
	cub_check(data);
	cub_game(data);
}
