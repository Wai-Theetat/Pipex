/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:03:33 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/24 15:20:40 by tdharmar         ###   ########.fr       */
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

void	error_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}