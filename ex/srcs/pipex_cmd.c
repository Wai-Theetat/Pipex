/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:03:03 by pioncha2          #+#    #+#             */
/*   Updated: 2025/09/11 15:08:08 by pioncha2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_build_path(char *path, char *cmd)
{
	char	*temp_path;
	char	*cmd_path;

	temp_path = ft_strjoin(path, "/");
	cmd_path = ft_strjoin(temp_path, cmd);
	free(temp_path);
	return (cmd_path);
}

char	*ft_get_cmd_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*cmd_path;

	i = 0;
	while (envp[i] != NULL && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i] != NULL)
	{
		cmd_path = ft_build_path(paths[i], cmd);
		if (access(cmd_path, F_OK) == 0)
		{
			ft_free_strs(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free_strs(paths);
	return (NULL);
}

void	ft_run_cmd(char *cmd_str, char **envp)
{
	char	**cmd;
	char	*cmd_path;

	if (cmd_str == NULL || envp == NULL)
		return ;
	cmd = ft_split(cmd_str, ' ');
	cmd_path = ft_get_cmd_path(cmd[0], envp);
	if (cmd_path == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
		ft_free_strs(cmd);
		exit(127);
	}
	if (execve(cmd_path, cmd, envp) == -1)
	{
		ft_free_strs(cmd);
		free(cmd_path);
		ft_error("pipex");
	}
}
