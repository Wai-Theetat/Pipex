/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:12:41 by pioncha2          #+#    #+#             */
/*   Updated: 2025/09/13 14:46:43 by pioncha2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(char **argv, char **envp, int *fds)
{
	int	fd_input;

	close(fds[R_IDX]);
	fd_input = open(argv[1], O_RDONLY);
	if (fd_input == -1)
	{
		close(fds[W_IDX]);
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
	dup2(fd_input, STDIN_FILENO);
	dup2(fds[W_IDX], STDOUT_FILENO);
	close(fd_input);
	close(fds[W_IDX]);
	ft_run_cmd(argv[2], envp);
}

void	ft_parent_process(char **argv, char **envp, int *fds)
{
	int	fd_output;

	close(fds[W_IDX]);
	fd_output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_output == -1)
	{
		close(fds[R_IDX]);
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putstr_fd(argv[4], 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
	dup2(fds[R_IDX], STDIN_FILENO);
	dup2(fd_output, STDOUT_FILENO);
	close(fds[R_IDX]);
	close(fd_output);
	ft_run_cmd(argv[3], envp);
}
