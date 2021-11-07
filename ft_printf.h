/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:27:29 by spurple           #+#    #+#             */
/*   Updated: 2021/11/07 17:52:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_flags {
	int	minus;
	int	width;
	int width2;
	int	zero;
	int	dot;
	int	grid;
	int	space;
	int	plus;
	int	star;
	int star2;
	int	len;
}	t_flags;
int		ft_printf(const char *sep, ...);
char	*hexadecimal(unsigned int num, int cas);
char	*rev(char *str);
int		ft_count(int num, int base);
int		put_x(char *str, int ptr, va_list argv);
int	put_X(char *str, int ptr, va_list argv);
int		parsing(const char *string, t_flags *check_flags, int i, va_list argv);
int		dot(const char *save, int start,t_flags *flags, va_list args);
int		check_type(char chr);
int		put_percent(const char *sep, va_list argv, t_flags *check_flags, int i);
int		put_int(t_flags *check_flags, va_list argv);
int put_pointer(char *str, int ptr, va_list argv);
t_flags	init_list(void);
char	*rev(char *str);

#endif

//static char	*treat_base(unsigned long long ull_save, int base,
//						 char *rtn, int count)
//						 {
//	while (ull_save != 0)
//	{
//		if ((ull_save % base) < 10)
//			rtn[count - 1] = (ull_save % base) + 48;
//		else
//			rtn[count - 1] = (ull_save % base) + 55;
//		ull_save /= base;
//		count--;
//	}
//	return (rtn);
//						 }
//
//						 char		*ft_ull_base(unsigned long long ull, int base)
//						 {
//	char				*rtn;
//	unsigned long long	ull_save;
//	int					count;
//
//	rtn = 0;
//	count = 0;
//	ull_save = ull;
//	if (ull == 0)
//		return (ft_strdup("0"));
//	while (ull != 0)
//	{
//		ull /= base;
//		count++;
//	}
//	if (!(rtn = malloc(sizeof(char) * (count + 1))))
//		return (0);
//	rtn[count] = '\0';
//	rtn = treat_base(ull_save, base, rtn, count);
//	return (rtn);
//						 }