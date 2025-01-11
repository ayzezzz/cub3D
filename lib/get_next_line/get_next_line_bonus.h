/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:01:00 by zayaz             #+#    #+#             */
/*   Updated: 2024/01/15 15:00:41 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_nlcntrl(char *stc);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_readfd(int fd, char *stc);
int		ft_strlen(char *c);
char	*ft_nlbefore(char *stc);
char	*ft_updtstc(char *stc);
#endif