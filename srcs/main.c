/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:46:41 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/20 14:15:39 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	static int	io_fd[2] = {0};

	if (argc < 5)
	{
		ft_putstr_fd("Error: Invalid number of arguments", 2);
		return (1);
	}
	open_file(io_fd, argv[1], argv[argc - 1]);
	check_arg_err(argc, argv, envp, io_fd);
	pipex(argc, argv, envp, io_fd);
	return (0);
}