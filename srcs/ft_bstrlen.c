/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:12:52 by dmulish           #+#    #+#             */
/*   Updated: 2017/07/23 16:42:08 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_bstrlen(wchar_t *s)
{
	int		i;
	size_t	n;

	n = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] < 128)
			n++;
		else if (s[i] > 127 && s[i] < 2048)
			n += 2;
		else if (s[i] > 2047 && s[i] < 65536)
			n += 3;
		else if (s[i] > 65535 && s[i] < 1114112)
			n += 4;
	}
	return (n);
}
