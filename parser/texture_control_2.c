/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_control_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:39:54 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/05 20:25:54 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

int	texture_error(t_data *data, char *clean_str)
{
	int	set;

	set = set_texture(data, clean_str);
	if (set)
	{
		if (set == 2)
			return (printf("Color format error! 🥺\n"), 0);
		else if (set == 1)
			return (printf("Invalid path error! 🥺\n"), 0);
	}
	return (1);
}

int	is_two_comma(char *clean_str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (clean_str[i])
	{
		if (clean_str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

int	is_invalid_character(char **int_str)
{
	int		i;
	char	*tmp;
	int		j;

	j = 0;
	i = 0;
	while (int_str[i])
	{
		tmp = ft_strtrim(int_str[i], " \n");
		j = 0;
		while (tmp[j])
		{
			if (!(tmp[j] >= '0' && tmp[j] <= '9') || (tmp[0] == '0' && tmp[1]
					&& ft_isdigit(tmp[1])))
				return (free(tmp), 0);
			j++;
		}
		free(tmp);
		i++;
	}
	return (1);
}

int	comma_in_fill(char **int_str)
{
	int	i;

	i = 0;
	while (int_str[i])
		i++;
	if (i != 3)
		return (0);
	return (1);
}
