/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:52:07 by dmulish           #+#    #+#             */
/*   Updated: 2017/05/30 20:21:48 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_d(t_mod *mod, t_s *s)
{
	char	*num;

	if (!mod->size)
		num = ft_itoa(va_arg(s->ap, int));
	((int)ft_strlen(num) >= mod->width) ? mod->width = 0 : 0;
	((int)ft_strlen(num) >= mod->prec) ? mod->prec = 0 : 0;
}
