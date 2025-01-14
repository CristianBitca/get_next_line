/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:18:40 by cbitca            #+#    #+#             */
/*   Updated: 2025/01/08 16:18:41 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return ((char *) NULL);
}

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char	*s)
{
	int		l;
	char	*buffer;

	l = str_len(s);
	buffer = malloc((l + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strcpy(buffer, s);
	return (buffer);
}

char	*ft_strjoin(char *dest, char *src)
{
	int		s_len;
	int		d_len;
	char	*buffer;

	s_len = str_len(src);
	d_len = str_len(dest);
	buffer = malloc((s_len + d_len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strcpy(buffer, dest);
	ft_strcpy(&buffer[d_len], src);
	return (buffer);
}
