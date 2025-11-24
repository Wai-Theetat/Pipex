/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:05:46 by pioncha2          #+#    #+#             */
/*   Updated: 2025/09/09 12:42:49 by pioncha2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str == NULL)
// 		return (0);
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

int	ft_is_newline(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	*arr;

// 	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (arr == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	len = ft_strlen(s1);
// 	while (j < len)
// 		arr[i++] = s1[j++];
// 	j = 0;
// 	len = ft_strlen(s2);
// 	while (j < len)
// 		arr[i++] = s2[j++];
// 	arr[i] = '\0';
// 	return (arr);
// }

char	*ft_append_free_first_str(char *s1, char *s2)
{
	char	*arr;

	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	arr = ft_strjoin(s1, s2);
	if (s1 != NULL)
		free(s1);
	return (arr);
}

char	*ft_calloc_char(size_t size)
{
	size_t		i;
	char		*arr;

	arr = malloc(size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		arr[i++] = '\0';
	return (arr);
}
