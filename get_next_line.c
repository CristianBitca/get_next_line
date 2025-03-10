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
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = ft_strdup(buffer);
	line = get_new_line(fd, line, buffer);
	if (str_len(line) == 0)
		return (free(line), NULL);
	rest(line, buffer);
	return (line);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while ((str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	int	file;
// 	char	*ret;
// 	char	buffer[BUFFER_SIZE];
// 	int	lineno = 0;

// 	file = open("name.txt", O_RDONLY);
// 	while ((ret = get_next_line(file)))
// 	{
// 		printf("%d: \"%s\" (len = %d)\n", lineno, ret, str_len(ret));
// 		printf("%d\n", ft_strcmp(ret, "2"));
// 		free(ret);
// 		lineno++;
// 	}
// 	close(file);
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