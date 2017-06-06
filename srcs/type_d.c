/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:52:07 by dmulish           #+#    #+#             */
/*   Updated: 2017/06/06 17:15:37 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_spaces_d(t_mod *mod, char *num, int sign, t_s *s)
{
	int	i;
	int	len;
	int	num_len;

	i = -1;
	num_len = (num[0] == '-') ? (int)ft_strlen(num) - 1 : (int)ft_strlen(num);
	len = (num_len >= mod->prec) ? num_len : mod->prec;
	if (!ft_strchr(mod->flags, '0'))
	{
		while (++i < (mod->width - len - sign))
			s->return_val += write(1, " ", 1);
	}
}

void	type_zeros_d(t_mod *mod, char *num, int sign, t_s *s)
{
	int	i;
	int	num_len;

	i = -1;
	num_len = (num[0] == '-') ? (int)ft_strlen(num) - 1 : (int)ft_strlen(num);
	if (ft_strchr(mod->flags, '+') || num[0] == '-')
		s->return_val += (num[0] == '-') ? write(1, "-", 1) : write(1, "+", 1);
	else if (ft_strchr(mod->flags, ' '))
		s->return_val += (num[0] == '-') ? write(1, "-", 1) : write(1, " ", 1);
	if (ft_strchr(mod->flags, '0'))
	{
		while (++i < (mod->width - num_len - sign))
			s->return_val += write(1, "0", 1);
	}
	else if (mod->prec > num_len)
	{
		while (++i < (mod->prec - num_len))
			s->return_val += write(1, "0", 1);
	}
}

void	type_d(t_mod *mod, t_s *s)
{
	int		val;
	int		sign;
	char	*num;

	val = va_arg(s->ap, int);
	if (!mod->size)
		num = ft_itoa(val);
	sign = (ft_strchr(mod->flags, '+') || ft_strchr(mod->flags, ' ') ||
		num[0] == '-') ? 1 : 0;
	if ((int)ft_strlen(num) >= mod->width || (mod->prec >= mod->width))
		mod->width = 0;
	if ((int)ft_strlen(num) >= mod->prec)
		mod->prec = 0;
	if (ft_strchr(mod->flags, '-'))
	{
		type_zeros_d(mod, num, sign, s);
		(mod->flags && num[0] == '-') ? ft_putstr(num + 1) : ft_putstr(num);
		type_spaces_d(mod, num, sign, s);
	}
	else
	{
		type_spaces_d(mod,num, sign, s);
		type_zeros_d(mod, num, sign, s);
		(mod->flags && num[0] == '-') ? ft_putstr(num + 1) : ft_putstr(num);
	}
	s->return_val += ft_strlen(ft_itoa(ABS(val)));
}
