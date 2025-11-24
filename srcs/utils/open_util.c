/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:20:18 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/24 14:39:11 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(int io_fd[2], char *infile, char *outfile)
{
	if (!infile)
	{
		io_fd[0] = 0;
		io_fd[1] = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		io_fd[0] = open(infile, O_RDONLY);
		io_fd[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
}
