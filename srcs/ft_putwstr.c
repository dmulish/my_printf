/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:15:44 by dmulish           #+#    #+#             */
/*   Updated: 2017/07/18 02:35:44 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwstr(wchar_t *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putwchar(str[i]);
}
