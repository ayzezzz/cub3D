/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:01:03 by zayaz             #+#    #+#             */
/*   Updated: 2024/01/15 14:16:50 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readfd(int fd, char *stc)
{
	char	*buffer;
	int		control;

	buffer = malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	control = 1;
	while (!ft_nlcntrl(stc) && control != 0)
	{
		control = read(fd, buffer, BUFFER_SIZE);
		if (control == -1)
		{
			free(stc);
			free(buffer);
			return (NULL);
		}
		buffer[control] = '\0';
		stc = ft_strjoin(stc, buffer);
	}
	free(buffer);
	return (stc);
}

char	*ft_nlbefore(char *stc)
{
	char	*str;
	int		i;

	i = 0;
	if (!stc[i])
		return (NULL);
	while (stc[i] != '\n' && stc[i])
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stc[i] != '\n' && stc[i])
	{
		str[i] = stc[i];
		i++;
	}
	if (stc[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_updtstc(char *stc)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (stc[i] && stc[i] != '\n')
		i++;
	if (!stc[i])
	{
		free(stc);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stc) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stc[i])
		str[j++] = stc[i++];
	str[j] = '\0';
	free(stc);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*stc[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stc[fd] = ft_readfd(fd, stc[fd]);
	if (!stc[fd] || !*stc[fd])
	{
		if (stc[fd])
			free(stc[fd]);
		stc[fd] = NULL;
		return (NULL);
	}
	str = ft_nlbefore(stc[fd]);
	stc[fd] = ft_updtstc(stc[fd]);
	return (str);
}
