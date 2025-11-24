/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:05:36 by pioncha2          #+#    #+#             */
/*   Updated: 2025/09/01 14:27:32 by pioncha2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_fd(int fd, char *result)
{
	char	*buffer;
	int		bytes_read;

	if (result == NULL)
		result = ft_calloc_char(1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(result);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		result = ft_append_free_first_str(result, buffer);
		if (ft_is_newline(result))
			break ;
	}
	free(buffer);
	return (result);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	int		size;
	char	*arr;

	i = 0;
	if (buffer == NULL)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	size = i;
	arr = ft_calloc_char(size + 2);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		arr[i] = '\n';
	return (arr);
}

char	*ft_get_next(char *buffer)
{
	char	*arr;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	arr = ft_calloc_char(ft_strlen(buffer) - i + 1);
	if (arr == NULL)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	i++;
	while (buffer[i] != '\0')
		arr[j++] = buffer[i++];
	free(buffer);
	return (arr);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_fd(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_get_next(buffer[fd]);
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
