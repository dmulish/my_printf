/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:47:15 by dmulish           #+#    #+#             */
/*   Updated: 2017/07/12 14:50:47 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*putnum_u(char *s, unsigned long long num, int *i)
{
	if (num > 9)
	{
		putnum_u(s, num / 10, i);
		(*i)++;
	}
	s[*i] = num % 10 + '0';
	return (s);
}

char	*ft_itoa_ulong(unsigned long long n)
{
	int					i;
	char				*res;
	unsigned long long	num;

	i = 0;
	num = n;
	if (!(res = (char *)malloc(sizeof(char) * (ft_digitnum(num) + 1))))
		return (0);
	res = putnum_u(res, num, &i);
	res[i + 1] = '\0';
	return (res);
}
