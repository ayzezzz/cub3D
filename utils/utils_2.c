/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:19:23 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/05 19:41:16 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void	free_texture_check(t_data *data, char *str, char *clean_str, int fd)
{
	go_gnl_last(fd, str);
	free(clean_str);
	textures_free(data);
	free(str);
	free(data);
}
