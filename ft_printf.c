/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:27:13 by spurple           #+#    #+#             */
/*   Updated: 2021/11/13 13:38:30 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsigned(va_list argv)
{
	unsigned int	u_num;
	int				len;

	u_num = va_arg(argv, unsigned int );
	unsigned_put_num(u_num, 1);
	len = ft_count_base(u_num, 10);
	return (len);
}

int	check_type(char chr)
{
	return (chr == 'c' || chr == 's' || chr == 'p' || chr == 'd' || chr == 'i'
		|| chr == 'u' || chr == 'x' || chr == 'X' || chr == '%');
}

int	print(const char *sep, va_list argv, int i)
{
	int		num;
	int		len;

	len = 0;
	if (sep[i] == 'd' || sep[i] == 'i')
	{
		num = va_arg (argv, int);
		ft_putnbr_fd(num, 1);
		len = ft_count(num, 10);
	}
	else if (sep[i] == 'u')
		len = put_unsigned(argv);
	else if (sep[i] == 'c')
		len = ft_putchar_fd(va_arg (argv, int ), 1);
	else if (sep[i] == 's')
		len = print_str(argv);
	else if (sep[i] == '%')
		len = ft_putchar_fd('%', 1);
	else if (sep[i] == 'p')
		len = put_pointer(argv);
	else if (sep[i] == 'X')
		len = put_X(argv);
	else if (sep[i] == 'x')
		len = put_x(argv);
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	argv;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(argv, string);
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1])
		{
			if (check_type(string[i++]))
				len += print(string, argv, i);
		}
		else
		{
			ft_putchar_fd(string[i], 1);
			len++;
		}
		i++;
	}
	va_end(argv);
	return (len);
}
