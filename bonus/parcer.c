/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:09:41 by spurple           #+#    #+#             */
/*   Updated: 2021/11/07 13:11:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int check_type(char chr)
{
	return ((chr == 'c') || (chr == 's') || (chr == 'p') || (chr == 'd') || (chr == 'i')
	|| (chr == 'u') || (chr == 'x') || (chr == 'X') || (chr == '%'));
}

t_flags	init_list(void)
{
	t_flags	list_init;

	list_init.dot = 0;
	list_init.width = 0;
	list_init.grid = 0;
	list_init.minus = 0;
	list_init.plus = 0;
	list_init.space = 0;
	list_init.len = 0;
	list_init.zero = 0;
	list_init.star = 0;
	return (list_init);
}

int	parsing(const char *string, t_flags *check_flags, int i, va_list argv)
{
	while (string[i])
	{
		if (string[i] == '0' && check_flags->width == 0 &&
		check_flags->minus == 0)
			check_flags->zero = 1;
		if (string[i] == '.')
			dot(string, i, check_flags);
		else if (string[i] == '-')
		{
			check_flags->minus = 1;
			check_flags->zero = 0;
		}
		else if (string[i] == '*')
		{
			check_flags->star += 1;
			if (check_flags->star == 1)
				check_flags->width = va_arg(argv, int);
			if (check_flags->width < 0)
			{
				check_flags->minus = 1;
				check_flags->width *= -1;
			}
		}
		else if (string[i] == '#')
			check_flags->grid = 1;
		else if (string[i] == '+')
			check_flags->plus = 1;
		if (string[i] == ' ')
		{
			if (check_flags->space == 0)
				write(1," ", 1);
			check_flags->space = 1;
		}
		if (check_type(string[i]))
			break;
		i++;
	}
	return (i);
}