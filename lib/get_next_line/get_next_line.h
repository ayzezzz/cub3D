/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:03:27 by zayaz             #+#    #+#             */
/*   Updated: 2024/01/02 17:31:54 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_nlbefore(char *stc);
char	*ft_updtstc(char *stc);
char	*ft_readfd(int fd, char *stc);
int		ft_nlcntrl(char *s);
int		ft_strlen(char *c);
char	*ft_strjoin(char *s1, char *s2);

#endif