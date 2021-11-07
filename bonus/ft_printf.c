/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:27:13 by spurple           #+#    #+#             */
/*   Updated: 2021/11/07 14:16:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

void	put_x(char *str, int ptr, va_list argv)
{
	ptr = va_arg (argv, int);
	str = hexadecimal(ptr);
	ft_putstr_fd(str, 1);
	free(str);
}

void	put_X(char *str, int ptr, va_list argv)
{
	ptr = va_arg (argv, int);
	str = hexadecimal(ptr);
	ft_putstr_fd(str, 1);
	free(str);
}

int	count_char(const char *string, va_list argv)
{
	int	i;
	int	len;
	t_flags	check_flag;

	i = 0;
	len = 0;
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1])
		{
			check_flag = init_list();
			i = parsing(string, &check_flag, ++i, argv);
			if (check_type(string[i]))
			{
				len += put_percent(string, argv, check_flag, i);
			}
			else
				ft_putchar_fd(string[i], 1);
		}
		else
			ft_putchar_fd(string[i], 1);
		i++;
	}
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	argv;
	int		len;

	len = 0;
	va_start(argv, string);
	len += count_char(string, argv);
	va_end(argv);
	return (len);
}

int main()
{
	int i;
	char *res;

	res = "qwe";
	i = 0;
//	ft_printf("hello %.10d %s %c %i %% %u %X :ft_printf\n", 1, "string", 'c',
//			  5, 10, 7589);
//	printf("hello %.10d %0*d %s %c %i %% %u %X :ft_printf\n", 1, 8, 15,
//		   "string",
//		   'c',
//			  5, 10, 7589);
ft_printf("hello %d %5.4d :ft_printf\n",  15, -20, -17, 5);
printf("hello %d %*.*d :ft_printf\n",  15, -20, -17, 5);
	return 0;
}