/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:22:25 by spurple           #+#    #+#             */
/*   Updated: 2021/11/07 13:04:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	len_num(int ptr)
{
	int	j;

	j = 0;
	while (ptr > 0)
	{
		ptr /= 10;
		j++;
	}
	return (j);
}

int	dot_init(int star, int dot, int zero, int ptr)
{
	int	i;
	int	j;

	i = 0;
	j = len_num(ptr);
	while (i < dot - j)
	{
		if (star > 0)
		{
			if (zero > 0)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
		else
			ft_putchar_fd('0', 1);
		i++;
	}
	return 0;
}

int	star_init(int zero, int width, int *ptr, int star, va_list argv)
{
	int	i;
	int	j;
	int	minus;
	int	next;

	i = 0;
	j = len_num(*ptr);
	next = 0;
	minus = *ptr;
	if (star == 2)
	{
		while (i < width - *ptr)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		next = va_arg(argv, int);
		*ptr = next;
	}
	if (next < 0)
	{
		write(1, "-", 1);
		next *= -1;
	}
	if (minus > 0)
	{
		while (i++ < width - j)
		{
			if (zero > 0)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
	}
	else
	{
		while (++i < width - j - 1)
			ft_putchar_fd(' ', 1);
		write(1,"-", 1);
		*ptr *= -1;
	}
	return (0);
}

int	put_int(t_flags *check_flags, va_list argv)
{
	int	ptr;

	ptr = va_arg (argv, int);
	if (check_flags->plus > 0)
	{
		if (ptr > 0)
			write(1, "+", 1);
		else
		{
			write(1, "-", 1);
			ptr *= -1;
		}
	}
	if (check_flags->minus > 0)
	{
		ft_putnbr_fd(ptr, 1);
		if (check_flags->dot > 0)
			dot_init(check_flags->star, check_flags->dot, check_flags->zero, ptr);
		else if (check_flags->star > 0)
			star_init(check_flags->zero, check_flags->width, &ptr,check_flags->star, argv);
	}
	else
	{
		if (check_flags->dot > 0)
			dot_init(check_flags->star, check_flags->dot, check_flags->zero, ptr);
		else if (check_flags->star > 0)
			star_init(check_flags->zero, check_flags->width, &ptr,check_flags->star, argv);
		ft_putnbr_fd(ptr, 1);
	}
	return (0);
}
