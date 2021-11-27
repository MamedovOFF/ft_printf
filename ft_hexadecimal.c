/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:54:22 by spurple           #+#    #+#             */
/*   Updated: 2021/11/13 14:46:56 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*rev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

int	ft_count(int num, int base)
{
	int		num_save;
	int		j;

	num_save = num;
	j = 0;
	if (num < 0)
	{
		j++;
		num = -num;
	}
	while (num_save)
	{
		num_save /= base;
		j++;
	}
	if (j == 0)
		return (1);
	return (j);
}

int	ft_count_base( unsigned long long num, int base)
{
	unsigned long long	num_save;
	int					j;

	num_save = num;
	j = 0;
	if (num < 0)
	{
		j++;
		num = -num;
	}
	while (num_save)
	{
		num_save /= base;
		j++;
	}
	if (j == 0)
		return (1);
	return (j);
}

char	*hexadecimal(unsigned long long num, int cas)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = ft_count_base(num, 16);
	if (num == 0)
		return (ft_strdup("0"));
	res = (char *)malloc(sizeof(char) * (j + 1));
	while (num)
	{
		if ((num % 16) < 10)
			res[i] = (num % 16) + 48;
		else
			res[i] = ((num % 16) + 55) + cas;
		num /= 16;
		i++;
	}
	res[i] = 0;
	return (rev(res));
}
