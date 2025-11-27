/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:56:27 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/27 10:04:26 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		error_exit("Pipe");
	pid1 = fork();
	if (pid1 == 0)
		child_one(argv, envp, fd);
	pid2 = fork();
	if (pid2 == 0)
		child_two(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
