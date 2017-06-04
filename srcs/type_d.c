/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:52:07 by dmulish           #+#    #+#             */
/*   Updated: 2017/06/04 04:08:07 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_spaces_d(t_mod *mod, char *num, int sign)
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
			write(1, " ", 1);
	}
}

void	type_zeros_d(t_mod *mod, char *num, int sign)
{
	int	i;
	int	num_len;

	i = -1;
	num_len = (num[0] == '-') ? (int)ft_strlen(num) - 1 : (int)ft_strlen(num);
	if (ft_strchr(mod->flags, '+') || num[0] == '-')
		(num[0] == '-') ? write(1, "-", 1) : write(1, "+", 1);
	else if (ft_strchr(mod->flags, ' '))
		(num[0] == '-') ? write(1, "-", 1) : write(1, " ", 1);
	if (ft_strchr(mod->flags, '0'))
	{
		while (++i < (mod->width - num_len - sign))
			write(1, "0", 1);
	}
	else if (mod->prec > num_len)
	{
		while (++i < (mod->prec - num_len))
			write(1, "0", 1);
	}
}

void	type_d(t_mod *mod, t_s *s)
{
	int		sign;
	char	*num;

	if (!mod->size)
		num = ft_itoa(va_arg(s->ap, int));
	sign = (ft_strchr(mod->flags, '+') || ft_strchr(mod->flags, ' ') ||
		num[0] == '-') ? 1 : 0;
	if ((int)ft_strlen(num) >= mod->width || (mod->prec >= mod->width))
		mod->width = 0;
	if ((int)ft_strlen(num) >= mod->prec)
		mod->prec = 0;
	if (ft_strchr(mod->flags, '-'))
	{
		type_zeros_d(mod, num, sign);
		(mod->flags && num[0] == '-') ? ft_putstr(num + 1) : ft_putstr(num);
		type_spaces_d(mod, num, sign);
	}
	else
	{
		type_spaces_d(mod,num, sign);
		type_zeros_d(mod, num, sign);
		// ft_putstr(num);
		(mod->flags && num[0] == '-') ? ft_putstr(num + 1) : ft_putstr(num);
	}
}
