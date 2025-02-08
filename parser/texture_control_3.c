/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_control_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:13:41 by zayaz             #+#    #+#             */
/*   Updated: 2025/02/07 15:14:50 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

int	check_color_values(char **int_str)
{
	int		i;
	int		num;
	char	*tmp;

	i = 0;
	while (i < 3)
	{
		tmp = ft_strtrim(int_str[i], " \n");
		num = ft_atoi(tmp);
		if (ft_strlen(tmp) > 3 || (ft_strlen(tmp) == 0) || ft_strchr(tmp, 32)
			|| !(num >= 0 && num <= 255))
		{
			free(tmp);
			return (0);
		}
		free(tmp);
		i++;
	}
	return (1);
}

char	**find_color_num(t_data *data, char *clean_str, int type)
{
	char	**int_str;

	data->textures.check_list[type] += 1;
	if (data->textures.check_list[type] > 1)
	{
		if (type == F)
			double_str_free(data->textures.f);
		else if (type == C)
			double_str_free(data->textures.c);
		return (NULL);
	}
	if (clean_str[0] != 32)
		return (NULL);
	int_str = ft_split(clean_str, ',');
	if (!is_two_comma(clean_str) || !is_invalid_character(int_str))
		return (double_str_free(int_str), NULL);
	if (!comma_in_fill(int_str))
		return (double_str_free(int_str), NULL);
	if (!check_color_values(int_str))
	{
		double_str_free(int_str);
		return (NULL);
	}
	return (int_str);
}

void	getter_texture(t_data *data, char *clean_str, int index, char **texture)
{
	data->textures.check_list[index] += 1;
	if (clean_str[0] != 32)
		return ;
	if (data->textures.check_list[index] == 1)
		*texture = find_texture_path(clean_str);
}
