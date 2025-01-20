/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:09:31 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/20 17:34:39 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include "fcntl.h"

typedef struct s_textures
{
    char *no;
    char *so;
    char *we;
    char *ea;
    char **f;
    char **c;
    
}t_textures;

typedef struct s_player
{

}t_player;

typedef struct s_data
{
    t_textures textures;
    char ** map;
    char **cpymap;
    t_player player;

}t_data;

void error_message(char *str);
void file_path_control(char *argv);
int cub_check(t_data *data);


#endif



