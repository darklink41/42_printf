/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oint_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:46 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/26 18:41:51 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_oint_conversion(t_flags *flags)
{
	if (!flags->h && !flags->l && !flags->j && !flags->j && !flags->z)
		flags->raw = ft_itoabase(va_arg(*(flags->ap), unsigned int), 8);
	else if (flags->h == 2)
		flags->raw = ft_itoabase((unsigned char)va_arg(*(flags->ap), \
					unsigned int), 8);
	else if (flags->h == 1)
		flags->raw = ft_itoabase((unsigned short)va_arg(*(flags->ap), \
					unsigned int), 8);
	else if (flags->l == 1)
		flags->raw = ft_itoabase((unsigned long)va_arg(*(flags->ap), \
					unsigned long int), 8);
	else if (flags->l == 2)
		flags->raw = ft_itoabase(va_arg(*(flags->ap),unsigned \
					long long), 8);
	else if (flags->j == 1)
		flags->raw = ft_itoabase((uintmax_t)va_arg(*(flags->ap), \
					uintmax_t), 8);
	else if (flags->z == 1)
		flags->raw = ft_itoabase((size_t)va_arg(*(flags->ap), size_t), 8);
}

void	ft_oint_arg(t_flags *flags)
{
	ft_oint_conversion(flags);
	ft_set_priority(flags);
	flags->malloc_len = ft_malloc_len(flags);
	flags->edited = (char*)ft_strnew(flags->malloc_len + 1);
	if (!flags->edited)
		return;
	if (flags->left_adjusting)
		ft_edit_raw_left(flags);
	else
		ft_edit_raw(flags);
}