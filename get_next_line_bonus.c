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


void	rest(char *line, char *buffer)
{
	int		to_copy;
	char	*new_line;

	new_line = ft_strchr(line, '\n');
	to_copy = 0;
	if (new_line)
	{
		to_copy = new_line - line + 1;
		ft_strcpy(buffer, new_line + 1);
	}
	else
	{
		to_copy = str_len(line);
		buffer[0] = '\0';
	}
	line[to_copy] = '\0';
}

char	*get_new_line(int fd, char *line, char *buffer)
{
	char	*new_line;
	int		count;

	if (line && ft_strchr(line, '\n'))
		return (line);
	while (1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
			break ;
		buffer[count] = '\0';
		new_line = ft_strchr(buffer, '\n');
		line = ft_strjoin(line, buffer);
		if (new_line)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 16)
		return (NULL);
	line = ft_strdup(buffer[fd]);
	line = get_new_line(fd, line, buffer[fd]);
	if (str_len(line) == 0)
		return (free(line), NULL);
	rest(line, buffer[fd]);
	return (line);
}

// int	main(void)
// {
// 	int	file1;
// 	int	file2;
// 	char	*ret1;
// 	char	*ret2;
// 	char	buffer[BUFFER_SIZE];
// 	file1 = open("name.txt", O_RDONLY);
// 	file2 = open("name2.txt", O_RDONLY);
// 	while (ret1 && ret2)
// 	{
// 		ret1 = get_next_line(file1);
// 		printf("%s\n", ret1);
// 		ret2 = get_next_line(file2);
// 		printf("%s\n", ret2);
// 	}
// 	close(file1);
// 	return (0);
// }
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