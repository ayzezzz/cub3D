/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:31:25 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/03 15:26:41 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

int key_release(int keycode, t_data *data)
{
     if(keycode == 119)
        data->key.w = 0;
    if(keycode == 115)
        data->key.s = 0;
    if(keycode == 97 )
        data->key.a = 0;
    if(keycode == 100 )
        data->key.d = 0;
     if(keycode == 65363)
        data->key.right_p = 0;
    if(keycode == 65361)
        data->key.left_p = 0;
    return 0;
}

int key_press(int keycode,t_data *data)
{
    if(keycode == 65307)
    {
        free_image(data->cub_mlx);
        free(data->cub_mlx);
        free_data(data);
        printf("GAME OVER BY BY 😎\n");
        exit(1);
    }
    if(keycode == 119)
        data->key.w = 1;
    if(keycode == 115)
        data->key.s = 1;
    if(keycode == 97 )
        data->key.a = 1;
    if(keycode == 100 )
        data->key.d = 1;
     if(keycode == 65363)
        data->key.right_p = 1;
    if(keycode == 65361)
        data->key.left_p = 1;
    return 0;
}
