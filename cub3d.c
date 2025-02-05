/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:36:09 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/05 17:15:57 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./lib/cub3D.h"


static void cub_game(t_data *data)
{
    find_dir(data);
    game_start(data);
}

static void cub_check(t_data *data)
{
    texture_count_check(data);
    is_xpm_file(data);
    map_check(data);
}
int main(int argc, char **argv)
{
    if (argc != 2)
        error_message("Invalid Argumanet!!! 🥺\n");
    file_path_control(argv[1]);
    t_data *data;
    data = (t_data *)ft_calloc(1, sizeof(t_data));
    data->path = argv[1];
    cub_check(data);
    cub_game(data);
}
