/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:04:44 by pioncha2          #+#    #+#             */
/*   Updated: 2025/08/29 11:41:11 by pioncha2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_str(char *str)
{
	int	i;

	if (str == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	return (i);
}

int	ft_put_nbr(int nbr)
{
	long	n;
	int		cnt;

	n = nbr;
	cnt = 0;
	if (n < 0)
	{
		cnt += ft_put_char('-');
		n *= -1;
	}
	if (n < 10)
		cnt += ft_put_char(n + '0');
	else
	{
		cnt += ft_put_nbr(n / 10);
		cnt += ft_put_char(n % 10 + '0');
	}
	return (cnt);
}

int	ft_put_nbr_unsigned(unsigned int nbr)
{
	long	n;
	int		cnt;

	n = nbr;
	cnt = 0;
	if (n < 10)
		cnt += ft_put_char(n + '0');
	else
	{
		cnt += ft_put_nbr(n / 10);
		cnt += ft_put_char(n % 10 + '0');
	}
	return (cnt);
}
