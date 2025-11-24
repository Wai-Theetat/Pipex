/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:00:06 by pioncha2          #+#    #+#             */
/*   Updated: 2025/09/13 14:53:51 by pioncha2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_empty_cmds(int argc, char **argv)
{
	int		i;
	int		cnt;

	i = 2;
	cnt = 0;
	while (i < argc - 1)
	{
		if (ft_strlen(argv[i]) == 0)
			cnt++;
		i++;
	}
	return (cnt);
}

void	ft_pipex1(char **argv, char **envp)
{
	int		fds[2];
	pid_t	pid1;

	if (pipe(fds) == -1)
		ft_error("pipex");
	pid1 = fork();
	if (pid1 == -1)
		ft_error("pipex");
	if (pid1 == 0)
		ft_child_process(argv, envp, fds);
	else
	{
		waitpid(pid1, NULL, 0);
		ft_parent_process(argv, envp, fds);
	}
}

void	ft_pipex2(char **argv, char **envp)
{
	int		fds[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fds) == -1)
		ft_error("pipex");
	pid1 = fork();
	if (pid1 == -1)
		ft_error("pipex");
	if (pid1 == 0)
		ft_child_process(argv, envp, fds);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("pipex");
	if (pid2 == 0)
	{
		waitpid(pid1, NULL, 0);
		ft_parent_process(argv, envp, fds);
	}
	close(fds[R_IDX]);
	close(fds[W_IDX]);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	cnt;

	if (argc == 5)
	{
		cnt = ft_check_empty_cmds(argc, argv);
		if (cnt != 0)
		{
			while (cnt > 0)
			{
				ft_putstr_fd("pipex: permission denied:\n", 2);
				cnt--;
			}
			exit(126);
		}
		if (ft_get_file_size(argv[1]) > 10000)
			ft_pipex2(argv, envp);
		else
			ft_pipex1(argv, envp);
	}
	else
		ft_putstr_fd("Error: Invalid arguments\n", 1);
}

/*

Normal case:
./pipex Makefile "cat" "wc -l" output1
< Makefile cat | wc -l > output2

Invalid infile:
./pipex Makefilex "cat" "wc -l" output1
< Makefilex cat | wc -l > output2

Invalid cmd1:
./pipex Makefile "catx" "wc -l" output1
< Makefile catx | wc -l > output2

Invalid cmd2:
./pipex Makefile "cat" "wcxxx" output1
< Makefile cat | wcxxx > output2

Invalid cmd1&cmd2:
./pipex Makefile "catx" "wcxxx" output1
< Makefile catx | wcxxx > output2

Empty cmd1 
./pipex Makefile "" "wc -l" output1
<  Makefile "" | wc -l > output2

Empty cmd2 
./pipex Makefile "cat" "" output1
<  Makefile cat | "" > output2

Empty cmd1 & cmd2 
./pipex Makefile "" "" output1
<  Makefile "" | "" > output2

*/