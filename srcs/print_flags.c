/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:28:41 by dmulish           #+#    #+#             */
/*   Updated: 2017/06/09 18:07:00 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flags(t_mod *mod, t_s *s)
{
	if (mod->type == 'd' || mod->type == 'i')
		type_d(mod, s);
	else if (mod->type == 'D' || mod->type == 'u' || mod->type == 'U')
		type_big_d(mod, s);
	else if (mod->type == 'o')
		type_o(mod, s);
	else if (mod->type == 'x' || mod->type == 'X')
		type_x(mod, s);
	else if (mod->type == 's')
		type_s(mod, s);
}
