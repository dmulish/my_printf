/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:49:22 by dmulish           #+#    #+#             */
/*   Updated: 2017/07/17 17:29:04 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include "includes/ft_printf.h"

int		main(void)
{
	// wchar_t	str[] = L"хеллоῲ";
	setlocale(LC_ALL, "");
	// printf("%d\n", printf("  :%S\n", L"хеллоῲ 👧🏽"));
	// printf("%d\n", ft_printf("my:%S\n", L"хеллоῲ 👧🏽"));
	printf("%d\n", ft_printf("my:%s\n", "хеллоῲ 👧🏽"));
	// printf("1 %lu\n", ft_bstrlen(L"хеллоῲ"));
	// printf("2 %lu\n", strlen("хеллоῲ"));
	return (0);
}
