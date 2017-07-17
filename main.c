/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:49:22 by dmulish           #+#    #+#             */
/*   Updated: 2017/07/17 18:12:41 by dmulish          ###   ########.fr       */
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
	// printf("%d\n", printf("  :%S\n", L"£"));
	// printf("%d\n", ft_printf("my:%S\n", L"£"));
char str[4] = "    ";
str[0] = 226;
str[1] = 136;
str[2] = 145;

	printf("%s\n", str);
	return (0);
}
