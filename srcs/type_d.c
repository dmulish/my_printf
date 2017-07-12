/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:52:07 by dmulish           #+#    #+#             */
/*   Updated: 2017/07/12 15:45:46 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	deal_with_size_d(t_mod *mod, t_s *s)
{
	intmax_t	val;

	if (mod->size == 'h')
		val = (short)va_arg(s->ap, int);
	else if (mod->size == 'H')
		val = (signed char)va_arg(s->ap, int);
	else if (mod->size == 'l')
		val = va_arg(s->ap, long);
	else if (mod->size == 'L')
		val = va_arg(s->ap, long long);
	else if (mod->size == 'z')
		val = va_arg(s->ap, size_t);
	else if (mod->size == 'j')
		val = va_arg(s->ap, intmax_t);
	else
		val = va_arg(s->ap, int);
	return (val);
}

void		type_spaces_d(t_mod *mod, char *num, int sign, t_s *s)
{
	int	i;
	int	len;
	int	num_len;

	i = -1;
	num_len = (num[0] == '-') ? (int)ft_strlen(num) - 1 : (int)ft_strlen(num);
	len = (num_len >= mod->prec) ? num_len : mod->prec;
	if (!(ft_strchr(mod->flags, '0')))
	{
		while (++i < (mod->width - len - sign))
			s->return_val += write(1, " ", 1);
	}
	else if ((ft_strchr(mod->flags, '0') && ft_strchr(mod->flags, '.')))
	{
		s->spaces_d = mod->width - len - sign;
		while (++i < s->spaces_d)
			s->return_val += write(1, " ", 1);
	}
	if (ft_strchr(mod->flags, '.'))
	{
		if (mod->width && !mod->prec && !ft_strcmp(num, "0"))
			s->return_val += write(1, " ", 1);
	}
}

void		type_zeros_d(t_mod *mod, char *num, int sign, t_s *s)
{
	int	i;
	int	num_len;

	i = -1;
	num_len = (num[0] == '-') ? (int)ft_strlen(num) - 1 : (int)ft_strlen(num);
	s->return_val += (ft_strchr(mod->flags, '.') && !mod->prec &&
		!ft_strcmp(num, "0")) ? 0 : num_len;
	if (ft_strchr(mod->flags, '+') || num[0] == '-')
		s->return_val += (num[0] == '-') ? write(1, "-", 1) : write(1, "+", 1);
	else if (ft_strchr(mod->flags, ' '))
		s->return_val += (num[0] == '-') ? write(1, "-", 1) : write(1, " ", 1);
	if (ft_strchr(mod->flags, '0'))
	{
		while (++i < (mod->width - num_len - sign - s->spaces_d))
			s->return_val += write(1, "0", 1);
	}
	else if (mod->prec > num_len)
	{
		while (++i < (mod->prec - num_len))
			s->return_val += write(1, "0", 1);
	}
}

void		type_d(t_mod *mod, t_s *s)
{
	int			sign;
	char		*num;
	long long	val;

	val = deal_with_size_d(mod, s);
	num = ft_itoa_long(val);
	sign = (ft_strchr(mod->flags, '+') || ft_strchr(mod->flags, ' ') ||
		num[0] == '-') ? 1 : 0;
	if (ft_strchr(mod->flags, '-'))
	{
		type_zeros_d(mod, num, sign, s);
		if (!(ft_strchr(mod->flags, '.') && mod->prec == 0 && val == 0))
			(mod->flags && num[0] == '-') ? ft_putstr(num + 1) : ft_putstr(num);
		type_spaces_d(mod, num, sign, s);
	}
	else
	{
		type_spaces_d(mod, num, sign, s);
		type_zeros_d(mod, num, sign, s);
		if (!(ft_strchr(mod->flags, '.') && mod->prec == 0 && val == 0))
			(mod->flags && num[0] == '-') ? ft_putstr(num + 1) : ft_putstr(num);
	}
}
