/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:46:48 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/06 18:02:17 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <limits.h>
#include <locale.h>

int	main(void)
{
	char *test;
	setlocale(LC_ALL, "");
//	printf("%2hhS, %hhS\n", 0, L"米米");
//	printf("printf : %i\n", printf("%.1S", L"米"));
//	printf("qwqe%.1C%S", L'米', 0);
//	printf("ft : %i\n", ft_printf("%.1S", L"米"));
//	ft_printf("%.4S", L"米");
//	ft_printf("%2hhS", 0);
//	ft_printf("%2hhS, %hhS\n", L"米米", 0);
//	ft_printf("%S", L"米米");
//	printf("printf : %i\n", ft_printf("%hhS, %hhS\n", 0, L"米米"));
	printf("%hhC\n", 0);
//	printf("%hhC, %hhC\n", 0, L'米');
	printf("%hhC\n", 0);
	ft_printf("%hhC, %hhC\n", 0, L'米');
//	printf("ptf %i\n", printf("{% S}", L""));
//	printf("ret = %i", ft_printf("% S", L""));
//	ft_printf("% S", L"");
//	ft_printf("%i", printf("%S", L""));
//	ft_printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	//printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
//	printf("%i", ft_printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
//	printf("{%05p}\n", 0);
//	printf("%.5p\n", 0);
//	ft_printf("%.5p\n", 0);
//	printf("%2.9p\n", 1234);
//	ft_printf("%2.9p\n", 1234);
	//ft_printf("%p\n", 0);
//	printf("%p\n", 0);
//	printf("%.0p, %.p\n", 0, 0);
//	ft_printf("%.0p, %.p\n", 0, 0);
//	printf("{%#.o}\n", 1);
//	ft_printf("{%#.o}\n", 1);

//	printf("%i ptf", printf("%.0p\n", 0));
//	printf("%i ptf", ft_printf("%.0p\n", 0));
//	ft_printf("%.0p\n", 0);
//	ft_printf("f%.0p, %.p\n", 0, 0);
	//printf("%i",printf("%Sasdasd", ""));
//	printf("ftptf %i\n", printf("{% S}", L""));
//	printf("%i\n" ,printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
//	printf("%i" ,ft_printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
//	ft_printf("%4.s\n", "42");
//	ft_putendl("");
//	ft_putendl("");
//	printf("%.1iC\n", L'±');
//	ft_printf("%.1C\n", L'±');
	return (0);
}
