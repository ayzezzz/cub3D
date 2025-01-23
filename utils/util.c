/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:50:56 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/23 19:34:36 by itulgar          ###   ########.fr       */
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
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}
