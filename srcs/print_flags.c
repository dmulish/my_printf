/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:28:41 by dmulish           #+#    #+#             */
/*   Updated: 2017/06/08 15:39:41 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flags(t_mod *mod, t_s *s)
{
	if (mod->type == 'd' || mod->type == 'D' || mod->type == 'i')
		type_d(mod, s);
}