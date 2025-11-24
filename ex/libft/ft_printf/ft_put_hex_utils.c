/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:04:44 by pioncha2          #+#    #+#             */
/*   Updated: 2025/08/29 11:41:30 by pioncha2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_lower(unsigned int n)
{
	char	*hex_list;
	int		cnt;

	hex_list = "0123456789abcdef";
	cnt = 0;
	if (n < 16)
		cnt += ft_put_char(hex_list[n]);
	else
	{
		cnt += ft_puthex_lower(n / 16);
		cnt += ft_put_char(hex_list[n % 16]);
	}
	return (cnt);
}

int	ft_puthex_upper(unsigned int n)
{
	char	*hex_list;
	int		cnt;

	hex_list = "0123456789ABCDEF";
	cnt = 0;
	if (n < 16)
		cnt += ft_put_char(hex_list[n]);
	else
	{
		cnt += ft_puthex_upper(n / 16);
		cnt += ft_put_char(hex_list[n % 16]);
	}
	return (cnt);
}

int	ft_puthex_long(unsigned long n)
{
	char	*hex_list;
	int		cnt;

	hex_list = "0123456789abcdef";
	cnt = 0;
	if (n < 16)
		cnt += ft_put_char(hex_list[n]);
	else
	{
		cnt += ft_puthex_long(n / 16);
		cnt += ft_put_char(hex_list[n % 16]);
	}
	return (cnt);
}

int	ft_puthex_address(unsigned long n)
{
	int		cnt;

	cnt = 0;
	if (n != 0)
	{
		cnt = ft_put_str("0x");
		cnt += ft_puthex_long(n);
	}
	else
		cnt = ft_put_str("(nil)");
	return (cnt);
}
