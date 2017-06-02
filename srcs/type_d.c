/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:52:07 by dmulish           #+#    #+#             */
/*   Updated: 2017/06/02 20:16:57 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_spaces_d(t_mod *mod, int sign)
{
	int	i;

	i = -1;
	if (!ft_strchr(mod->flags, '0') || (ft_strchr(mod->flags, '0') &&
			ft_isdigit(*(ft_strchr(mod->flags, '0') - 1))))
	{
		while (++i < (mod->width - mod->prec - sign))
			write(1, " ", 1);
	}
}

void	type_zeros_d(t_mod *mod, char *num)
{
	int	i;
	int	len1;
	int	len2;

	i = -1;
	len1 = (mod->width > mod->prec) ? mod->width : mod->prec;
	len2 = (mod->width > mod->prec) ? mod->prec : mod->width;
	if (ft_strchr(mod->flags, '+'))
		(num[0] == '-') ? write(1, "-", 1) : write(1, "+", 1);
	else if (ft_strchr(mod->flags, ' '))
		(num[0] == '-') ? write(1, "-", 1) : write(1, " ", 1);
	if (len1 - (int)ft_strlen(num) > 0)
	{
		while (++i < (len1 - len2))
			write(1, "0", 1);
	}
}

void	type_d(t_mod *mod, t_s *s)
{
	int		sign;
	char	*num;

	sign = (ft_strchr(mod->flags, '+') || ft_strchr(mod->flags, ' ')) ? 1 : 0;
	if (!mod->size)
		num = ft_itoa(va_arg(s->ap, int));
	if ((int)ft_strlen(num) >= mod->width || (mod->prec >= mod->width))
		mod->width = 0;
	if ((int)ft_strlen(num) >= mod->prec)
		mod->prec = 0;
	if (ft_strchr(mod->flags, '-'))
	{
		type_zeros_d(mod, num);
		ft_putstr(num);
		type_spaces_d(mod, sign);
	}
	else
	{
		type_spaces_d(mod, sign);
		type_zeros_d(mod, num);
		ft_putstr(num);
	}
}
