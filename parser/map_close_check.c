/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_close_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:38:03 by zayaz             #+#    #+#             */
/*   Updated: 2025/02/03 19:28:49 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static char **allocate_b_map(t_data *data)
{
    int i = 0;

    data->cub_map.b_map = malloc((data->cub_map.b_col + 1) * sizeof(char *));
    if (!data->cub_map.b_map)
    {
        error_message("Memory allocation failed for b map! 🥺\n");
        return NULL;
    }

    while (i < data->cub_map.b_col)
    {
        data->cub_map.b_map[i] = malloc((data->cub_map.b_row + 1) * sizeof(char));
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

static void fill_b_map(t_data *data)
{
    int i = 0;
    
    while (i < data->cub_map.b_col)
    {
        int j = 0;
        while (j < data->cub_map.b_row)
        {
            data->cub_map.b_map[i][j] = 'B';
            j++;
        }
        data->cub_map.b_map[i][j] = '\0';
        i++;
    }
    data->cub_map.b_map[i] = NULL;   
}

static void copy_b_map_data(t_data *data)
{
    int i = 0;

    while (i < data->cub_map.b_col - 2)
    {
        int j = 0;
        while ( j < (int)ft_strlen(data->cub_map.map[i]))
        {
            if (data->cub_map.map[i] != NULL && data->cub_map.b_map[i] != NULL)
            {
                if (i < data->cub_map.b_col && j < data->cub_map.b_row)
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

static void b_map_check(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->cub_map.b_col - 1)
    {
        j = 0;
        while (j < data->cub_map.b_row - 1)
        {
            if (data->cub_map.b_map[i][j] == '0')
            {
                if ((i > 0 && data->cub_map.b_map[i - 1][j] == 'B') ||
                    (i < data->cub_map.b_col - 1 && data->cub_map.b_map[i + 1][j] == 'B') ||
                    (j > 0 && data->cub_map.b_map[i][j - 1] == 'B') ||
                    (j < data->cub_map.b_row - 1 && data->cub_map.b_map[i][j + 1] == 'B'))
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
    data->cub_map.b_row = max_row_lenght(data) + 2;
    data->cub_map.b_col = max_col_length(data) + 2;
    data->cub_map.b_map = allocate_b_map(data);
    if (!data->cub_map.b_map)
        return;
    fill_b_map(data);
    copy_b_map_data(data);
    b_map_check(data);
}
