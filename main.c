/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:49:22 by dmulish           #+#    #+#             */
/*   Updated: 2017/07/22 12:56:57 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include "includes/ft_printf.h"

int		main(void)
{
	// wchar_t	str[] = L"хеллоῲ";
	setlocale(LC_ALL, "");
	// printf("%d\n", printf("%25S\n", L"челлоῲ 👧"));
	// printf("%d\n", ft_printf("%25S\n", L"хеллоῲ 👧"));
	printf("%d\n", printf("1)%.2S\n", L"@@"));
	printf("%d\n", ft_printf("2)%.2S\n", L"@@"));
	// printf("%d\n", printf("%.4S\n", L"helno"));
	// printf("%d\n", ft_printf("%.4S\n", L"hello"));
	return (0);
}
