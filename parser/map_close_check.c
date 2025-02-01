/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_close_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:38:03 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/26 20:48:55 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static char **allocate_b_map(t_data *data,size_t max_row, size_t max_col)
{
    size_t i = 0;

    data->cub_map.b_map = malloc((max_col + 1) * sizeof(char *));
    if (!data->cub_map.b_map)
    {
        error_message("Memory allocation failed for b map! 🥺\n");
        return NULL;
    }

    while (i < max_col)
    {
        data->cub_map.b_map[i] = malloc((max_row + 1) * sizeof(char));
        if (!data->cub_map.b_map[i])
        {
            free_data(data);
            error_message("Memory allocation failed for b map row! 🥺\n");
            return NULL;
        }
        i++;
    }

    return (data->cub_map.b_map);
}

static void fill_b_map(t_data *data, size_t max_row, size_t max_col)
{
    size_t i = 0;
    
    while (i < max_col)
    {
        size_t j = 0;
        while (j < max_row)
        {
            data->cub_map.b_map[i][j] = 'B';
            j++;
        }
        data->cub_map.b_map[i][j] = '\0';
        i++;
    }
    data->cub_map.b_map[i] = NULL;   
}

static void copy_b_map_data(t_data *data, size_t max_row, size_t max_col)
{
    size_t i = 0;

    while (i < max_col - 2)
    {
        size_t j = 0;
        while ( j < ft_strlen(data->cub_map.map[i]))
        {
            if (data->cub_map.map[i] != NULL && data->cub_map.b_map[i] != NULL)
            {
                if (i < max_col && j < max_row)
                {
                    if (data->cub_map.map[i][j] != ' ' && data->cub_map.map[i][j] != '\0')
                        data->cub_map.b_map[i + 1][j + 1] = data->cub_map.map[i][j];
                }
            }
            else
            {
                free_data(data);
                error_message("NULL pointer detected while copying map data! 🥺\n");
                return;
            }
            j++;
        }
        i++;
    }
}

static void b_map_check(t_data *data,size_t max_row, size_t max_col)
{
    size_t i;
    size_t j;

    i = 0;
    while (i < max_col - 1)
    {
        j = 0;
        while (j < max_row - 1)
        {
            if (data->cub_map.b_map[i][j] == '0')
            {
                if ((i > 0 && data->cub_map.b_map[i - 1][j] == 'B') ||
                    (i < max_col - 1 && data->cub_map.b_map[i + 1][j] == 'B') ||
                    (j > 0 && data->cub_map.b_map[i][j - 1] == 'B') ||
                    (j < max_row - 1 && data->cub_map.b_map[i][j + 1] == 'B'))
                {
                    free_data(data);
                    error_message("Map is not closed! 🥺\n");
                }
            }
            j++;
        }
        i++;
    }
}

void map_close_check(t_data *data)
{
    size_t max_row;
    size_t max_col;

    max_row = max_row_lenght(data) + 2;
    max_col = max_col_length(data) + 2;
    data->cub_map.b_map = allocate_b_map(data,max_row, max_col);
    if (!data->cub_map.b_map)
        return;
    fill_b_map(data, max_row, max_col);
    copy_b_map_data(data, max_row, max_col);
    b_map_check(data, max_row, max_col);
}
