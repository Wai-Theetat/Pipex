/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:46:41 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/24 15:05:23 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int io_fd[2];

	if (argc != 5)
	{
		ft_putstr_fd("Error: Invalid arguments\n", 2);
		exit(EXIT_FAILURE);
	}

	return (0);
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