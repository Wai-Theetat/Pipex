/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:56:27 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/01 11:10:57 by tdharmar         ###   ########.fr       */
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
		perror_no_file(file);
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

static pid_t	handle_outfile(int argc, char **argv, char **envp)
{
	int		fd;
	pid_t	pid;

	fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror_no_file(argv[argc - 1]);
		return (-1);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
		ft_execute(argv[argc - 2], envp);
	}
	close(fd);
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	last_pid;
	int		exit_code;
	int		status;

	if (argc < 5)
		error_exit("Invalid number of argument");
	handle_infile(argv[1]);
	pipex_loop(argc, argv, envp);
	last_pid = handle_outfile(argc, argv, envp);
	exit_code = 0;
	if (last_pid == -1)
		exit_code = 1;
	else
	{
		waitpid(last_pid, &status, 0);
		if (WIFEXITED(status))
			exit_code = WEXITSTATUS(status);
	}
	while (wait(NULL) > 0)
		;
	return (exit_code);
}
