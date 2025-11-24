/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:04:11 by pioncha2          #+#    #+#             */
/*   Updated: 2025/09/11 15:03:21 by pioncha2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	ft_get_file_size(char *file_path)
{
	int		file;
	int		count;
	int		bytes_read;
	char	buffer[BUFFER_SIZE];

	file = open(file_path, O_RDONLY);
	if (file < 0)
		return (-1);
	bytes_read = read(file, buffer, BUFFER_SIZE);
	count = 0;
	while (bytes_read > 0)
	{
		count += bytes_read;
		bytes_read = read(file, buffer, BUFFER_SIZE);
	}
	close(file);
	return (count);
}
