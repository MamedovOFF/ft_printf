/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:46:55 by spurple           #+#    #+#             */
/*   Updated: 2021/11/07 13:49:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_percent(const char *sep, va_list argv, int i)
{
	int		ptr;
	char	*str;

	str = NULL;
	ptr = 0;
	if (sep[i] == 'd' || sep[i] == 'i')
	{
		ptr = va_arg (argv, int);
		ft_putnbr_fd(ptr, 1);
	}
	else if (sep[i] == 'c')
	{
		ptr = va_arg (argv, int);
		ft_putchar_fd(ptr, 1);
	}
	else if (sep[i] == 's')
	{
		str = va_arg (argv, char *);
		ft_putstr_fd(str, 1);
	}
	else if (sep[i] == '%')
		ft_putchar_fd('%', 1);
	else if (sep[i] == 'X')
		put_X(str, ptr, argv);
	else if (sep[i] == 'x')
		put_x(str, ptr, argv);
	return (i);
}