/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:46:41 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/24 15:49:44 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		empty_cnt;

	if (argc != 5)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	empty_cnt = ft_check_empty_cmds(argc, argv);
	if (empty_cnt > 0)
	{
		while (empty_cnt--)
			ft_putstr_fd("pipex: permission denied:\n", 2);										//<-- Real sh does not exit here
	}
	return (0);
}
