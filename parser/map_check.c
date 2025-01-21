/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:53:49 by zayaz             #+#    #+#             */
/*   Updated: 2025/01/21 11:54:14 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

// int map_check(t_data *data)
// {
//     int i = 0;
//     int fd;
//     char *line;
//     fd = open(data->path,O_RDONLY);
    
//     while (1)
//     {
//         data->map.map[i] = get_next_line(fd);
//         if (!data->map.map[i])
//             break ;
//         i++;
//     }
//     close(fd);
//     exit(1);
//     return 0;
//     //wall_check();
//     //player_check();  wrong character 1 0 ' ' S N W E F C
//     //player_count();
//     //character_check();
//     //blank_check();
//     // if(data.map[])
//     // eles if()
// }