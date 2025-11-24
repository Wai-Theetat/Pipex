/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:59:32 by pioncha2          #+#    #+#             */
/*   Updated: 2025/08/29 11:14:16 by pioncha2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_format(va_list args, char c)
{
	int				cnt;
	unsigned long	addr;

	cnt = 0;
	if (c == 'c')
		cnt = ft_put_char(va_arg(args, int));
	else if (c == 's')
		cnt = ft_put_str(va_arg(args, char *));
	else if (c == 'p')
	{
		addr = va_arg(args, unsigned long);
		cnt = ft_puthex_address(addr);
	}
	else if (c == 'd' || c == 'i')
		cnt = ft_put_nbr(va_arg(args, int));
	else if (c == 'u')
		cnt = ft_put_nbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		cnt = ft_puthex_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		cnt = ft_puthex_upper(va_arg(args, unsigned int));
	else if (c == '%')
		cnt = ft_put_char('%');
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		cnt;
	va_list	args;

	i = 0;
	cnt = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				i++;
				cnt += ft_put_format(args, format[i]);
			}
		}
		else
			cnt += ft_put_char(format[i]);
		i++;
	}
	va_end(args);
	return (cnt);
}
