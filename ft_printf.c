/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:27:13 by spurple           #+#    #+#             */
/*   Updated: 2021/11/07 17:20:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	put_x(char *str, int ptr, va_list argv)
{
	int	len;

	ptr = va_arg (argv,unsigned int);
	str = hexadecimal(ptr, 32);
	len = (int)ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	put_X(char *str, int ptr, va_list argv)
{
	int	len;

	ptr = va_arg (argv,unsigned int);
	str = hexadecimal(ptr, 0);
	len = (int)ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int put_pointer(char *str, int ptr, va_list argv)
{
	int	len;

	ptr = va_arg (argv, unsigned int);
	str = hexadecimal(ptr, 0);
	len = (int)ft_strlen(str);
	write(1, "0x", 2);
	ft_putstr_fd(str, 1);
	free(str);
	return (len +  2);
}

int	put_percent(const char *sep, va_list argv, t_flags *check_flags, int i)
{
	int		ptr;
	int		len;
	char	*str;

	str = NULL;
	len = 0;
	ptr = 0;
	if (sep[i] == 'd' || sep[i] == 'i')
	{
		ptr = va_arg (argv, int);
		ft_putnbr_fd(ptr, 1);
		len = ft_count(ptr, 10);
	}
	else if (sep[i] == 'c')
	{
		ptr = va_arg (argv, int);
		ft_putchar_fd(ptr, 1);
		len++;
	}
	else if (sep[i] == 's')
	{
		str = va_arg (argv, char *);
		if (!str)
			str = "(null)";
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
	}
	else if (sep[i] == '%')
	{
		ft_putchar_fd('%', 1);
		len++;
	}
	else if (sep[i] == 'p')
		len = put_pointer(str, ptr, argv);
	else if (sep[i] == 'X')
		len = put_X(str, ptr, argv);
	else if (sep[i] == 'x')
		len = put_x(str, ptr, argv);
	return (len);
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

int check_type(char chr)
{
	return ((chr == 'c') || (chr == 's') || (chr == 'p') || (chr == 'd') || (chr == 'i')
	|| (chr == 'u') || (chr == 'x') || (chr == 'X') || (chr == '%'));
}

int	dot(const char *save, int start,t_flags *flags, va_list args)
{
	int i;

	i = start;
	i++;
	if (save[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(save[i]))
			flags->dot = (flags->dot * 10) + (save[i++] - '0');
	}
	return (i);
}

int	parsing(const char *string, t_flags *check_flags, int i, va_list argv)
{
	while (string[i])
	{
		if (string[i] == '0' && check_flags->width == 0 &&
		check_flags->minus == 0)
		{
			check_flags->zero = 1;
			i++;
		}
		else if (string[i] == '.')
		{
			dot(string, i, check_flags, argv);
			i++;
		}
		else if (string[i] == '-')
		{
			check_flags->minus = 1;
			check_flags->zero = 0;
			i++;
		}
		else if (string[i] == '*')
		{
			check_flags->star = 1;
			check_flags->width = va_arg(argv, int);
			if (check_flags->width < 0)
			{
				check_flags->minus = 1;
				check_flags->width *= -1;
			}
		}
		else if (string[i] == '#')
		{
			check_flags->grid = 1;
			i++;
		}
		else if (string[i] == ' ')
		{
			check_flags->space = 1;
			i++;
		}
		else if (string[i] == '+')
		{
			check_flags->plus = 1;
			i++;
		}
		if (check_type(string[i]))
			break;
	}
	return (i);
}

int	count_char(const char *string, t_flags check_flag, va_list argv)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1])
		{
			i = parsing(string, &check_flag, ++i, argv);
			if (check_type(string[i]))
				len += put_percent(string, argv, &check_flag, i);
		}
		else if (string[i] != '%')
		{
			ft_putchar_fd(string[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	argv;
	t_flags	check_flag;
	int		len;

	len = 0;
	va_start(argv, string);
	check_flag = init_list();
	len += count_char(string, check_flag, argv);
	va_end(argv);
	return (len);
}

int main()
{
	int		i;
	int		j;
	char	*res;

	res = "qwe";
	i = 0;
	j = ft_printf(" %X ", -2);
	printf("\n%d\n", j);
	j = printf(" %X ", -2);
	printf("\n%d\n", j);
	return 0;
}
//("hello")
//("hello %-d %s %c %i %% %u %X :ft_printf\n", 1, "string", 'c',
//		5, 10, 7589);