/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:09:16 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/04 12:51:44 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"


int main(int argc, char **argv)
{
    if(argc != 2)
        error_message("Invalid Argumanet!!! 🥺\n");
    file_path_control(argv[1]);
    t_data *data;
    data=(t_data*) ft_calloc(1,sizeof(t_data));
    data->path = argv[1];
    if(!cub_check(data))
    {
        free(data);
        return 0;
    }
    cub_game(data);
    free(data->rayc);
    free_data(data);
   
}
