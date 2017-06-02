/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:47:09 by dmulish           #+#    #+#             */
/*   Updated: 2017/06/02 17:19:21 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
#include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_mod
{
	int			prec;
	int			size;
	int			type;
	int			width;
	char		*flags;
	char		*modifs;
}				t_mod;

typedef struct	s_s
{
	int			return_val;
	int			param_num;
	int			error;
	va_list		ap;
}				t_s;

int				ft_printf(char *str, ...);

void			type_d(t_mod *mod, t_s *s);
void			print_flags(t_mod *mod, t_s *s);
void			handle_modif(char *str, int *i, t_s *s);

#endif
