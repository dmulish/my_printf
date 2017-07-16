/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:49:22 by dmulish           #+#    #+#             */
/*   Updated: 2017/07/16 17:56:16 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include "includes/ft_printf.h"

int		main(void)
{
	// setlocale(LC_ALL, "");
	// printf("%d\n", printf("  :%S\n", L"хелло"));
	// printf("%d\n", ft_printf("my:%S\n", L"хелло"));
	printf("1 %lu\n", ft_bstrlen(L"хеллоῲ"));
	printf("2 %lu\n", strlen("хеллоῲ"));
	return (0);
}
