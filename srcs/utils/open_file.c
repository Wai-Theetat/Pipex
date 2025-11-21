/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:17:22 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/20 14:42:29 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(int io_fd[2], char *infile, char *outfile)
{
	if (!infile)
	{
		io_fd[0] = 0;
		io_fd[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else
	{
		io_fd[0] = open(outfile, O_RDONLY);
		io_fd[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
}

void	check_arg_err(int argc, char **argv, char **envp, int io_fd[2])
{
	if (io_fd[1] == -1)
	{
		perror("Error opening outfile");
		cloesfd(io_fd[0]);
		cloesfd(io_fd[1]);
		exit(EXIT_FAILURE);
	}
}
