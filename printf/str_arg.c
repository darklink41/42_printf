/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:46 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/31 18:31:46 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wchar_string(t_flags *flags, wchar_t *save)
{
	int		len;
	char	*str;

	len = 0;
	flags->raw = ft_strnew(4);
	while (save[len] != 0)
	{
		ft_handle_unicode(flags, (int)save[len]);
		printf("len = %i, raw_len = %i\n", len, flags->raw_len);
	//	printf("%i\n", save[len]);
		str = ft_memnjoin(str, flags->raw, len, flags->raw_len);
	ft_print_flags(flags);
		len += flags->raw_len;
	}
	str[len + 1] = '\0';
	flags->raw = str;
	flags->raw_len = len;
	ft_print_flags(flags);
}

void	ft_str_conversion(t_flags *flags)
{
	wchar_t	*save;

	if (flags->l != 1)
		flags->raw = ft_strdup(va_arg(*(flags->ap), char*));
	else
	{
		save = (va_arg(*(flags->ap), wchar_t*));
		ft_wchar_string(flags, save);
	}
}

void	ft_str_arg(t_flags *flags)
{
	ft_length_priority(flags);
	ft_str_conversion(flags);
	if (!(flags->raw))
	{
		flags->malloc_len = 6;
		flags->edited = ft_strdup("(null)");
		return ;
	}
	ft_set_priority(flags);
	if (flags->raw_len == 0)
		flags->precision = 0;
	if (flags->precision && flags->raw_len && flags->conversion != 'S')
	{
		ft_bzero(flags->raw + flags->precision, flags->raw_len - flags->precision);
		flags->raw_len = ft_strlen(flags->raw);
	}
	flags->malloc_len = ft_malloc_len(flags);
	flags->edited = (char*)ft_strnew(flags->malloc_len);
	if (!flags->edited)
		return;
	if (flags->left_adjusting)
		ft_edit_raw_left(flags);
	else
		ft_edit_raw(flags);
}
