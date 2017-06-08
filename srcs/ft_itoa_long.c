/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:44:46 by dmulish           #+#    #+#             */
/*   Updated: 2017/06/08 19:05:30 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*putnum(char *s, intmax_t num, int *i)
{
	if (num > 9)
	{
		putnum(s, num / 10, i);
		(*i)++;
	}
	s[*i] = num % 10 + '0';
	return (s);
}

char	*ft_itoa_long(long long n)
{
	char		*res;
	int			i;
	intmax_t	num;

	i = 0;
	num = n;
	if (num < 0)
	{
		if (!(res = (char *)malloc(sizeof(char) * (ft_digitnum(n) + 2))))
			return (0);
		res[i] = '-';
		num *= -1;
		i++;
	}
	else if (!(res = (char *)malloc(sizeof(char) * (ft_digitnum(n) + 1))))
		return (0);
	res = putnum(res, num, &i);
	res[i + 1] = '\0';
	return (res);
}
