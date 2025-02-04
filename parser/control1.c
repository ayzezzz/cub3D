/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:01:34 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/04 19:56:12 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static int is_cub_extension(char *path)
{
    size_t i;
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return error_message("File Error 🥺\n"), 0;
    close(fd);
    i = ft_strlen(path) - 1;
    if (!(path[i] == 'b' && path[i - 1] == 'u' && path[i - 2] == 'c' && path[i - 3] == '.'))
        return error_message("Not with .cub extension 🥺\n"), 0;

    return 1;
}

void file_path_control(char *argv)
{

    int fd;
    char *str;
    if (!is_cub_extension(argv))
        return;
    fd = open(argv, O_RDONLY);
    str = get_next_line(fd);
    if (str == NULL)
        error_message("Empty file 🥺\n");
    else
    {
        free(str);
        while (1)
        {
            if ((str = get_next_line(fd)) == NULL)
                break;
            free(str);
        }
    }
    free(str);
    close(fd);
}
