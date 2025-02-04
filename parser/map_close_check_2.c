/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_close_check_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:47:46 by zayaz             #+#    #+#             */
/*   Updated: 2025/02/04 13:22:56 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void b_map_check(t_data *data)
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

int max_row_lenght(t_data *data)
{
    size_t max_row;
    size_t tmp;
    int i;

    i = 0;
    max_row = 0;
    tmp = 0;
    while (i < data->cub_map.map_row)
    {
        tmp = ft_strlen(data->cub_map.map[i]);
        if (tmp > max_row)
            max_row = tmp;
        i++;
    }
    return (max_row);
}

int is_there_char(char *line)
{
    int i = 0;

    if (!line)
        return 0;
    while (line[i])
    {
        if (line[i] == 'N' || line[i] == 'S' ||
            line[i] == 'W' || line[i] == 'E' ||
            line[i] == '0' || line[i] == '1')
            return 1;
        i++;
    }
    return 0;
}

int max_col_length(t_data *data)
{
    size_t max_col = 0;
    size_t start = 0;
    size_t end = 0;

    while (data->cub_map.map[end])
        end++;

    while (end > 0 && !is_there_char(data->cub_map.map[end]))
        end--;

    while (data->cub_map.map[start] && !is_there_char(data->cub_map.map[start]))
        start++;

    if (end >= start)
        max_col = end - start + 1;
    return max_col;
}
