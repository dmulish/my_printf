/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:30:55 by dmulish           #+#    #+#             */
/*   Updated: 2017/06/10 13:28:23 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_spaces_c(t_mod *mod, t_s *s)
{
	int	i;

	i = -1;
	if (!ft_strchr(mod->flags, '0'))
	{
		while (++i < mod->width - 1)
			s->return_val += write(1, " ", 1);
	}
	else
	{
		while (++i < mod->width - 1)
			s->return_val += write(1, "0", 1);
	}
}

void	type_c(t_mod *mod, t_s *s)
{
	char	c;

	c = va_arg(s->ap, int);
	if (ft_strchr(mod->flags, '-'))
	{
		ft_putchar(c);
		s->return_val += 1;
		type_spaces_c(mod, s);
	}
	else
	{
		type_spaces_c(mod, s);
		ft_putchar(c);
		s->return_val += 1;
	}
}
