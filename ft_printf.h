/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:27:29 by spurple           #+#    #+#             */
/*   Updated: 2021/11/13 13:36:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *sep, ...);
int		check_type(char chr);
int		print(const char *sep, va_list argv, int i);
void	unsigned_put_num(unsigned int n, int fd);
int		put_pointer(va_list argv);
int		put_X(va_list argv);
int		put_x(va_list argv);
char	*hexadecimal(unsigned long long num, int cas);
int		ft_count(int num, int base);
char	*rev(char *str);
int		ft_count_base( unsigned long long num, int base);
int		print_str( va_list argv);
int		put_unsigned(va_list argv);

#endif
