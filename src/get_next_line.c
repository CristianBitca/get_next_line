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

//
// FUNCTION: rest
// ----------------------------
// Preserves the remaining part of the buffer after a newline is found.
// When a '\n' exists in the given line, this function copies everything
// after that newline into 'buffer', so it can be used on the next call
// to get_next_line(). The current 'line' is truncated right after '\n'.
//
// PARAMETERS
//	line:    The current line being processed.
//	buffer:  The static buffer that stores leftover data.
//
// RETURN VALUE
//	None (void). Modifies 'line' and 'buffer' in place.
//
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

//
// FUNCTION: get_new_line
// ----------------------------
// Reads data from a file descriptor into a temporary buffer until a
// newline character ('\n') or end-of-file (EOF) is reached.
// Each chunk read is appended to 'line' using ft_strjoin().
//
// PARAMETERS
//	fd:      The file descriptor to read from.
//	line:    The current accumulated line (can be partially filled).
//	buffer:  Temporary storage used to hold read data.
//
// RETURN VALUE
//	Returns the updated line containing all data up to the first '\n',
//	or until EOF is reached. Returns NULL only if memory allocation fails.
//
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

//
// FUNCTION: get_next_line
// ----------------------------
// Reads and returns a single line from a file descriptor.
// Successive calls to this function will return the next line
// each time, using a static buffer to store leftover data between calls.
//
// PARAMETERS
//	fd:  The file descriptor to read from.
//
// RETURN VALUE
//	Returns a string containing the next line from the file descriptor,
//	including the terminating '\n' character if one is found.
//	Returns NULL when there are no more lines to read or an error occurs.
//
// NOTES
//	This implementation uses a static buffer of size (BUFFER_SIZE + 1).
//	Make sure BUFFER_SIZE is defined before compilation.
//
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
