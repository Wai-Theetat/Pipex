/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:27:51 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/01 11:07:02 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>

void	error_exit(char *str);
void	perror_no_file(char *str);
void	ft_execute(char *cmd, char **envp);
char	*ft_find_path(char *cmd, char **envp);

void	pipex_loop(int argc, char **argv, char **envp);

void	ft_free_tab(char **tab);

#endif