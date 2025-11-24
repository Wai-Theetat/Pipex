/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:05:59 by pioncha2          #+#    #+#             */
/*   Updated: 2025/09/11 14:18:33 by pioncha2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

// get_next_line_utils.c
int		ft_is_newline(char *str);
char	*ft_append_free_first_str(char *s1, char *s2);
char	*ft_calloc_char(size_t size);

// get_next_line.h
char	*get_next_line(int fd);
char	*ft_read_fd(int fd, char *result);
char	*ft_get_line(char *buffer);
char	*ft_get_next(char *buffer);

#endif