/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:09:31 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/27 19:49:16 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include "fcntl.h"
#include "minilibx_linux/mlx.h"

#define s_width 1350
#define s_height 800
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

} t_textures;

typedef struct s_player
{
    int p_x; //loc
    int p_y; //loc
    char p_dir; //name
    int dir_x; // yönü
    int dir_y; // yönü
    int turn_angle; //dönme açısı
    double plane_x;
    double plane_y; //

} t_player;

typedef struct s_map
{
    char **map;
    char **b_map;
    char **cpymap;
    int map_row;

} t_map;

typedef struct s_mlx
{
    void *mlx;
    void *window;
    void *so;
    void *no;
    void *we;
    void *ea;
    void *img;
    void *addr;
    int endian;
    int bpp;
    int size_line;
    
}t_mlx;
typedef struct s_data
{
    t_textures textures;
    t_map cub_map;
    char *path;
    t_player player;
    t_mlx cub_mlx; 

} t_data;

void error_message(char *str);
void file_path_control(char *argv);
int cub_check(t_data *data);
int texture_count_check(t_data *data);
int map_check(t_data *data);
char *find_texture_path(t_data *data, char *clean_str);
void textures_free(t_data *data);
void map_free(t_data *data, char *line, int fd);
int is_xpm_file(t_data *data);
void double_str_free(char **str);
void go_gnl_last(int fd, char *line);
char *go_pass_textures(char *line, int fd);
void player_loc(t_data *data);
void find_color_num(t_data *data, char *clean_str);
void map_close_check(t_data *data);
int is_there_char(char *line);
int max_row_lenght(t_data *data);
int max_col_length(t_data *data);
void character_check(t_data *data);
void player_check(t_data *data);
void free_data(t_data *data);
void flood_fill_check(t_data *data);
void cub_game(t_data *data);
void find_dir(t_data *data);
void game_start(t_data *data);
#endif
