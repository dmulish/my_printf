/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:49:22 by dmulish           #+#    #+#             */
/*   Updated: 2017/07/23 18:12:05 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include "includes/ft_printf.h"

int		main(void)
{
	// wchar_t	str[] = L"хеллоῲ";
	// wchar_t	*str = 0;
	setlocale(LC_ALL, "");
	// printf("%d\n", printf("  :%S\n", L"челлоῲ 👧"));
	// printf("%d\n", ft_printf("my:%S\n", L"хеллоῲ 👧"));
	printf("%d\n", printf("  :%ls\n", L"@@"));
	printf("%d\n", ft_printf("my:%ls\n", L"@@"));
	return (0);
}
