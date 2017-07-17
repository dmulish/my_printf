/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:15:44 by dmulish           #+#    #+#             */
/*   Updated: 2017/07/17 16:42:51 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_blen(wchar_t *s)
{
	size_t	n;

	n = 0;
	if (*s < 128)
		n++;
	else if (*s > 127 && *s < 2048)
		n += 2;
	else if (*s > 2047 && *s < 65536)
		n += 3;
	else if (*s > 65535 && *s < 1114112)
		n += 4;
	return (n);
}

void	putbchar(wchar_t *s)
{
	int		i;
	int		size;

	i = -1;
	size = (int)ft_blen(s);
	while (++i < size)
		ft_putchar(((char*)(s))[i]);
}

void	ft_putbstr(wchar_t *s)
{
	int	i;

	i = -1;
	while (++i < (int)ft_bstrlen(s))
	{
		putbchar(s + i);
	}
}
