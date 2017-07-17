/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:15:44 by dmulish           #+#    #+#             */
/*   Updated: 2017/07/18 02:20:54 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wlen(wchar_t s)
{
	size_t	n;

	n = 0;
	if (s < 128)
		n++;
	else if (s > 127 && s < 2048)
		n += 2;
	else if (s > 2047 && s < 65536)
		n += 3;
	else if (s > 65535 && s < 1114112)
		n += 4;
	return (n);
}

void	putbchar(wchar_t s)
{
	int		size;
	char	*mbs;

	size = (int)ft_wlen(s);
	mbs = ft_strnew(size);
	size == 4 ? (mbs[3] = 240 | (s >> 18)) : 0;
	size == 4 ? (mbs[2] = 128 | (s >> 12 & 63)) : 0;
	size == 3 ? (mbs[2] = 224 | (s >> 12)) : 0;
	size >= 3 ? (mbs[1] = 128 | (s >> 6 & 63)) : 0;
	size == 2 ? (mbs[1] = 192 | (s >> 6)) : 0;
	mbs[0] = (size == 1) ? s : 128 | (s & 63);
	mbs = ft_revstr(mbs);
	ft_putstr(mbs);
	free(mbs);
}

void	ft_putbstr(wchar_t *str)
{
	int	i;

	i = -1;
	while (str[++i])
		putbchar(str[i]);
}
