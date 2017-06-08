/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:34:22 by dmulish           #+#    #+#             */
/*   Updated: 2017/06/08 19:05:29 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digitnum(long long n)
{
	size_t	i;

	i = 0;
	if (!n && n != 0)
		return (0);
	if (n == 0)
		return (1);
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}
