/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:09:31 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/24 17:34:58 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include "fcntl.h"

#define NO 0
#define SO 1
#define WE 2
#define EA 3
#define F 4
#define C 5

typedef struct s_textures
{
    char *no;
    char *so;
    char *we;
    char *ea;
    char **f;
    char **c;
    int check_list[6];
    
}t_textures;

typedef struct s_player
{

}t_player;

typedef struct s_map
{
    char **map;
    char **cpymap;
    int  map_row;
    
}t_map;

typedef struct s_data
{
    t_textures textures;
    t_map cub_map;
    char *path;
    t_player player;
    

}t_data;

void error_message(char *str);
void file_path_control(char *argv);
int cub_check(t_data *data);
int texture_count_check(t_data *data);
int map_check(t_data *data);
char* find_texture_path(t_data *data,char *clean_str);
void textures_free(t_data *data);
void map_free(t_data *data, char *line, int fd);
int is_xpm_file(t_data *data);
void double_str_free(char **str);
void go_gnl_last(int fd, char *line);
char *go_pass_textures( char *line, int fd);
int is_textures_top(t_data *data);
char **find_color_num(t_data *data,char* clean_str);
void map_close_check(t_data *data);

#endif



