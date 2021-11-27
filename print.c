/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:23:58 by spurple           #+#    #+#             */
/*   Updated: 2021/11/13 13:31:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_x(va_list argv)
{
	int		len;
	char	*str;

	str = hexadecimal(va_arg(argv, unsigned int), 32);
	len = (int)ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	put_X(va_list argv)
{
	int		len;
	char	*str;

	str = hexadecimal(va_arg(argv, unsigned int), 0);
	len = (int)ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	put_pointer(va_list argv)
{
	int		len;
	char	*str;

	str = hexadecimal(va_arg (argv, unsigned long long), 32);
	len = (int)ft_strlen(str);
	write(1, "0x", 2);
	ft_putstr_fd(str, 1);
	free(str);
	return (len + 2);
}

void	unsigned_put_num(unsigned int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = n * -1;
	}
	else
		num = n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

int	print_str( va_list argv)
{
	char	*str;

	str = va_arg (argv, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str));
}
