/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:09:22 by spurple           #+#    #+#             */
/*   Updated: 2021/11/07 13:04:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	put_percent(const char *sep, va_list argv, t_flags check_flags, int i)
{
	int		ptr;
	char	*str;

	str = NULL;
	ptr = 0;
	if (sep[i] == 'd' || sep[i] == 'i')
		put_int(&check_flags, argv);
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
