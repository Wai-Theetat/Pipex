/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:56:27 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/29 13:30:32 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handle_infile(char *file)
{
	int	fd;
	int	tmp_fd[2];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(file);
		if (pipe(tmp_fd) == -1)
			error_exit("Pipe error");
		close(tmp_fd[1]);
		dup2(tmp_fd[0], STDIN_FILENO);
		close(tmp_fd[0]);
	}
	else
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

static void	handle_outfile(int argc, char **argv, char **envp)
{
	int		fd;
	pid_t	pid;

	fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(argv[argc - 1]);
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
		ft_execute(argv[argc - 2], envp);
	}
	close(fd);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		error_exit("Invalid number of argument");
	handle_infile(argv[1]);
	pipex_loop(argc, argv, envp);
	handle_outfile(argc, argv, envp);
	while (wait(NULL) > 0)
		;
	return (0);
}
