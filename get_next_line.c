/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:18:29 by cbitca            #+#    #+#             */
/*   Updated: 2025/01/08 16:18:30 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include "get_next_line_utils.c"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			to_copy;

	line = ft_strdup(buffer);
	while (!(ft_strchr(line, '\n')) && read(fd, buffer, BUFFER_SIZE))
	{
		buffer[BUFFER_SIZE] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (str_len(line) == 0)
		return (free(line), NULL);
	if (ft_strchr(line, '\n'))
	{
		to_copy = (ft_strchr(line, '\n')) - line + 1;
		ft_strcpy(buffer, (ft_strchr(line, '\n')) + 1);
	}
	else
	{
		to_copy = str_len(line);
		buffer[0] = '\0';
	}
	line[to_copy] = '\0';
	return (line);
}

int	main(void)
{
	int	i;
	int	file;

	i = 3;
	file = open("name.txt", O_RDONLY);
	while (i)
	{
		printf("%s", get_next_line(file));
		i--;
	}
	close(file);
	return (0);
}

// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE];
// 	char		*line;
// 	char		*new_line;
// 	int			count;

// 	line = ft_strdup(buffer);
// 	while (1)
// 	{
// 		count = read(fd, buffer, BUFFER_SIZE);
// 		new_line = check_n(buffer);
// 		if (!new_line && count > 0)
// 			line = ft_strjoin(line, buffer);
// 		else
// 			break ;
// 	}
// 	if (new_line)
// 	{
// 		ft_strcpy(buffer, new_line);
// 		while (*new_line)
// 			*new_line++ = '\0';
// 	}
// 	if (!new_line)
// 		line = ft_strdup(buffer);
// 	return (line);
// }