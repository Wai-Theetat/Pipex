/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:26:42 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/24 14:26:44 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	i;

	if (argc < 5)
		exit_handler(1);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		if (argc < 6)
			exit_handler(1);
		i = 3;
	}
	else
	{
		i = 2;
		fd_in = open_file(argv[1], 0);
		fd_out = open_file(argv[argc - 1], 1);
		dup2(fd_in, 0);
	}
	return (0);
}