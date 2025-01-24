/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:50:56 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/24 15:54:05 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void error_message(char *str)
{
    printf("Error\n%s",str);
    exit(1);
}

void textures_free(t_data *data)
{
    free(data->textures.no);
    free(data->textures.we);
    free(data->textures.ea);
    free(data->textures.so);
}

void double_str_free(char **str)
{
    int i;
    i = 0;
    while(str && str[i])
    {
        free(str[i]);
        i++;
    }
    if(str)
        free(str);
}
