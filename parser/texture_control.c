/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:00:45 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/04 20:33:10 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static void init_check_list(t_data *data)
{
    int i;
    i = 0;
    while (i < 6)
        data->textures.check_list[i++] = 0;
}

static int is_fill_textures(t_data *data)
{
    int i;
    i = 0;
    while (i < 6)
    {
        if (data->textures.check_list[i] == 0 || data->textures.check_list[i] > 1)
            return 0;
        i++;
    }
    return 1;
}

static int set_texture(t_data *data, char *clean_str)
{
    if (clean_str[0] == 'N' && clean_str[1] == 'O' && clean_str[2] == ' ')
    {
        data->textures.check_list[NO] += 1;
        if (data->textures.check_list[NO] == 1)
            data->textures.no = find_texture_path(clean_str + 3);
    }
    else if (clean_str[0] == 'S' && clean_str[1] == 'O' && clean_str[2] == ' ')
    {
        data->textures.check_list[SO] += 1;
        if (data->textures.check_list[SO] == 1)
            data->textures.so = find_texture_path(clean_str + 3);
    }
    else if (clean_str[0] == 'W' && clean_str[1] == 'E' && clean_str[2] == ' ')
    {
        data->textures.check_list[WE] += 1;
        if (data->textures.check_list[WE] == 1)
            data->textures.we = find_texture_path(clean_str + 3);
    }
    else if (clean_str[0] == 'E' && clean_str[1] == 'A' && clean_str[2] == ' ')
    {
        data->textures.check_list[EA] += 1;
        if (data->textures.check_list[EA] == 1)
            data->textures.ea = find_texture_path(clean_str + 3);
    }
    else if ((clean_str[0] == 'F' && clean_str[1] == ' ') && (data->textures.check_list[F] += 1))
        data->textures.f = find_color_num(data, clean_str + 2);
    else if ((clean_str[0] == 'C' && clean_str[1] == ' ') && (data->textures.check_list[C] += 1))
        data->textures.c = find_color_num(data, clean_str + 2);
    if ((!data->textures.no || !data->textures.so || !data->textures.we || !data->textures.ea) && is_fill_textures(data))
        return 1;
    if ((!data->textures.f || !data->textures.c) && is_fill_textures(data))
        return 2;
    return 0;
}

static int texture_loop(t_data *data, int *i, char *str, int fd)
{
    while (*i < data->cub_map.map_row)
    {
        free(str);
        str = get_next_line(fd);
        (*i)++;
    }
    if (!is_fill_textures(data))
        return 0;

    return 1;
}

void texture_count_check(t_data *data)
{

    char *str;
    char *clean_str;
    int fd;
    int i;
    int set;
    i = 0;
    init_check_list(data);
    fd = open(data->path, O_RDONLY);
    while ((str = get_next_line(fd)))
    {
        clean_str = ft_strtrim(str, " \n");
        if ((clean_str[0] == '0' || clean_str[0] == '1') && !texture_loop(data, &i, str, fd))
        {
            free_texture_check(data, str, clean_str, fd);
            error_message("Invalid textures! 🥺\n");
        }
        if ((set = set_texture(data, clean_str)))
        {
            if (set == 2)
                printf("Must be in 0 - 255 format! 🥺\n");
            else if (set == 1)
                printf("Invalid path 🥺\n");
            free_texture_check(data, str, clean_str, fd);
            exit(1);
        }
        free(str);
        free(clean_str);
    }
    close(fd);
}
