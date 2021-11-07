/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:14:26 by spurple           #+#    #+#             */
/*   Updated: 2021/11/07 13:11:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	dot(const char *save, int start, t_flags *check_flags)
{
	int	i;

	i = start;
	i++;
	if (save[i] == '*')
		check_flags->zero = 1;
	else
	{
		check_flags->dot = 0;
		while (ft_isdigit(save[i]))
			check_flags->dot = (check_flags->dot * 10) + (save[i++] - '0');
	}
	return (0);
}