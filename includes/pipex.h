/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:27:51 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/24 14:41:47 by tdharmar         ###   ########.fr       */
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

void	open_file(int io_fd[2], char *infile, char *outfile);

#endif