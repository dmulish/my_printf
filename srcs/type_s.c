/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 18:05:44 by dmulish           #+#    #+#             */
/*   Updated: 2017/06/09 19:24:59 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_spaces_s(t_mod *mod, char *str, t_s *s)
{
	int	i;
	int	len;
	int	str_len;

	i = -1;
	str_len = (int)ft_strlen(str);
	len = (!mod->prec || !str_len) ? str_len : mod->prec;
	if (ft_strchr(mod->flags, '.'))
	{
		s->spaces_d = mod->width - len;
		while (++i < s->spaces_d)
			s->return_val += write(1, " ", 1);
	}
	if (mod->width)
	{
		while (++i < (mod->width - len))
			s->return_val += write(1, " ", 1);
	}
}

void	minus_s(t_mod *mod, t_s *s, char *str)
{
	int	i;

	i = -1;
	if (!mod->prec && ft_strlen(str))
	{
		ft_putstr(str);
		s->return_val += ft_strlen(str);
	}
	else if (ft_strlen(str))
	{
		while (++i < mod->prec)
			s->return_val += write(1, &str[i], 1);
	}
	type_spaces_s(mod, str, s);
}

void	type_s(t_mod *mod, t_s *s)
{
	int		i;
	char	*str;

	i = -1;
	if (!(str = va_arg(s->ap, char*)))
	{
		ft_putstr("(null)");
		s->return_val += 6;
	}
	if (ft_strchr(mod->flags, '-'))
		minus_s(mod, s, str);
	else
	{
		type_spaces_s(mod, str, s);
		if (!mod->prec && ft_strlen(str))
		{
			ft_putstr(str);
			s->return_val += ft_strlen(str);
		}
		else if (ft_strlen(str))
		{
			while (++i < mod->prec)
				s->return_val += write(1, &str[i], 1);
		}
	}
}
