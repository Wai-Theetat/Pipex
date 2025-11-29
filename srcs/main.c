/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:56:27 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/29 12:36:12 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		filein;
	int		fileout;
	pid_t	pid;

	if (argc < 5)
		error_exit("Invalid number of argument");
	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		 error_no_file(argv[1]);
	dup2(filein, STDIN_FILENO);
	close(filein);
	pipex_loop(argc, argv, envp);
	fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		error_exit("Error opening outfile");
	pid = fork();
	if (pid == 0)
	{
		dup2(fileout, STDOUT_FILENO);
		close(fileout);
		ft_execute(argv[argc - 2], envp);
	}
	close(fileout);
	while (wait(NULL) > 0)
	return (0);
}
