/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:56:57 by pioncha2          #+#    #+#             */
/*   Updated: 2025/09/11 14:18:23 by pioncha2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

# define R_IDX 0
# define W_IDX 1

void	ft_child_process(char **argv, char **envp, int *fds);
void	ft_parent_process(char **argv, char **envp, int *fds);
void	ft_error(char *str);
void	ft_free_strs(char **strs);
char	*ft_get_cmd_path(char *cmd, char **envp);
void	ft_run_cmd(char *cmd_str, char **envp);
int		ft_get_file_size(char *file_path);

#endif