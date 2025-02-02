/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:31:25 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/02 15:36:29 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

int key_press(int keycode,t_data *data)
{
    if(keycode == 65307)
    {
        free_image(data->cub_mlx);
        // free(data->rayc);
        free_data(data);
        printf("biy ehe 😸\n");
        exit(1);
    }
    // if(keycode == 119)
    //  printf("S\n");
    // if(keycode == 115)
        //printf("S\n");
    // if(keycode == 97 )
        //printf("A\n");
    // if(keycode == 100 )
        //printf("D\n");
     // if(keycode == 65363)
        //printf("sag acı\n");
    // if(keycode == 65361)
        //printf("sol\n");
    return 0;
}

