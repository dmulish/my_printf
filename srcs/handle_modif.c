/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_modif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 18:04:11 by dmulish           #+#    #+#             */
/*   Updated: 2017/05/29 20:02:19 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_mod(t_mod *mod)
{
	mod->prec = 0;
	mod->size = 0;
	mod->type = 0;
	mod->width = 0;
	mod->flags = ft_strdup("-+ #");
}

void	handle_modif(char *str, int *i, t_s *s)
{
	t_mod	mod;

	(void)s;
	(void)str;
	(void)i;
	init_mod(&mod);
	// if (ft_strchr(mod.flags, ))
		// handle_flags();
}
