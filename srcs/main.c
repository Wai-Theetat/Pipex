/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:46:41 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/24 14:41:14 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int io_fd[2];

	if (argc != 5)
	{
		ft_putstr_fd("Error: Invalid number of arguments", 2);
		exit(EXIT_FAILURE);
	}
	open_file(io_fd, argv[1], argv[argc - 1]);

	return (0);
}
