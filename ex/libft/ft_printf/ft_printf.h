/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:00:40 by pioncha2          #+#    #+#             */
/*   Updated: 2025/08/29 11:23:32 by pioncha2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// ft_put_utils.c
int	ft_put_char(char c);
int	ft_put_str(char *str);
int	ft_put_nbr(int nbr);
int	ft_put_nbr_unsigned(unsigned int nbr);

// ft_put_hex_utils.c
int	ft_puthex_lower(unsigned int n);
int	ft_puthex_upper(unsigned int n);
int	ft_puthex_long(unsigned long n);
int	ft_puthex_address(unsigned long n);

// ft_printf.c
int	ft_put_format(va_list args, char c);
int	ft_printf(const char *format, ...);

#endif