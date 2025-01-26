
#include "../lib/cub3D.h"

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
