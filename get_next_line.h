/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:18:49 by cbitca            #+#    #+#             */
/*   Updated: 2025/01/08 16:18:50 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

int		str_len(char *s);

char	*ft_strchr(const char *s, char c);
char	*get_next_line(int fd);
char	*ft_strdup(char	*s);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char *dest, char *src);

#endif