/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:16:17 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/27 16:04:31 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*ft_fillstr(unsigned long long sav[3], char *b_tab, int base, \
		char *s)
{
	while (sav[0] > 0)
	{
		s[sav[2]] = b_tab[(sav[1] / sav[0])];
		sav[1] %= sav[0];
		sav[0] /= base;
		sav[2]++;
	}
	s[sav[2]] = '\0';
	return (s);
}

char		*ft_uitoabase(unsigned long long int nbr, int base)
{
	char				*b_tab;
	unsigned long long	size[3];
	char				*s;

	b_tab = "0123456789abcdef";
	size[2] = 1;
	size[1] = nbr;
	size[0] = ft_intsize(size[1], base);
	if (!(s = (char*)malloc(sizeof(char) * (size[2] + ft_intlen(size[1]) \
						+ 1))))
		return (NULL);
	size[2] = 0;
	ft_fillstr(size, b_tab, base, s);
	return (s);
}
