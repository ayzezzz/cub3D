/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:38:03 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/24 20:57:17 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static char **allocate_b_map(size_t max_row, size_t max_col)
{
    size_t i = 0;

    char **b_map = malloc((max_row) * sizeof(char *));
    if (!b_map)
    {
        error_message("Memory allocation failed for b map! 🥺\n");
        return NULL;
    }

    while (i < max_row)
    {
        b_map[i] = malloc((max_col + 1) * sizeof(char));
        if (!b_map[i])
        {
            error_message("Memory allocation failed for b map row! 🥺\n");
            return NULL;
        }
        i++;
    }

    return b_map;
}

static void fill_b_map(char **b_map, size_t max_row, size_t max_col)
{
    size_t i = 0;
    while (i < max_row)
    {
        size_t j = 0;
        while (j < max_col)
        {
            b_map[i][j] = 'B';
            j++;
        }
        b_map[i][max_col] = '\0';
        i++;
    }
}

static void copy_b_map_data(t_data *data, char **b_map, size_t max_row, size_t max_col)
{
    size_t i = 0;

    while (i < max_row - 2)
    {
        size_t j = 0;
        while (j < ft_strlen(data->cub_map.map[i]))
        {
            if (data->cub_map.map[i] != NULL && b_map[i] != NULL)
            {
                if (i < max_row && j < max_col)
                {
                    if (data->cub_map.map[i][j] != ' ' && data->cub_map.map[i][j] != '\0')
                        b_map[i + 1][j + 1] = data->cub_map.map[i][j];
                }
            }
            else
            {
                error_message("NULL pointer detected while copying map data! 🥺\n");
                return;
            }
            j++;
        }
        i++;
    }
}

static void b_map_check(char **b_map, size_t max_row, size_t max_col)
{
    size_t i;
    size_t j;

    i = 0;
    while (i < max_row - 1)
    {
        j = 0;
        while (j < max_col - 1)
        {
            if (b_map[i][j] == 'B')
            {
                if ((i > 0 && b_map[i - 1][j] == '0') ||
                    (i < max_row - 1 && b_map[i + 1][j] == '0') ||
                    (j > 0 && b_map[i][j - 1] == '0') ||
                    (j < max_col - 1 && b_map[i][j + 1] == '0'))
                {
                    free_b_map(b_map, max_row);
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
    char **b_map;

    max_row = max_row_lenght(data) + 2;
    max_col = max_col_length(data) + 2;
    b_map = allocate_b_map(max_row, max_col);
    if (!b_map)
        return;
    fill_b_map(b_map, max_row, max_col);
    copy_b_map_data(data, b_map, max_row, max_col);
    b_map_check(b_map, max_row, max_col);

    // size_t i = 0;
    //  while (i < max_row + 2)
    //  {
    //      printf("b_map: %s\n", b_map[i]);
    //      i++;
    //  }
}
