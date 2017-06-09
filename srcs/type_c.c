/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:30:55 by dmulish           #+#    #+#             */
/*   Updated: 2017/06/09 19:38:37 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_spaces_c(t_mod *mod, t_s *s)
{
	int	i;

	i = -1;
	while (++i < mod->width)
		s->return_val += write(1, " ", 1);
}

void	minus_c(t_mod *mod, t_s *s, char c)
{
	int	i;

	i = -1;
	if (!mod->prec)
	{
		ft_putchar(c);
		s->return_val += 1;
	}
	else
	{
		while (++i < mod->prec)
			s->return_val += write(1, &c, 1);
	}
	type_spaces_c(mod, s);
}

void	type_c(t_mod *mod, t_s *s)
{
	int		i;
	char	c;

	i = -1;
	if (!(c = va_arg(s->ap, int)))
	{
		ft_putstr("(null)");
		s->return_val += 6;
	}
	if (ft_strchr(mod->flags, '-'))
		minus_c(mod, s, c);
	else
	{
		type_spaces_c(mod, s);
		if (!mod->prec)
		{
			ft_putchar(c);
			s->return_val += 1;
		}
		else
		{
			while (++i < mod->prec)
				s->return_val += write(1, &c, 1);
		}
	}
}
