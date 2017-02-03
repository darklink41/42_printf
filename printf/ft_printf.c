/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:35:04 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/03 01:06:07 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strparse(char *s, va_list *ap, void (**ptr_tab)(t_flags*), \
t_flags *flags)
{
	char	*buf;
	int		count;

	count = 0;
	while (*s)
	{
		if (*s && *s != '%')
		{
			if (ft_strchr(s, '%'))
			{
				buf = ft_memnjoin(buf, s, flags->ret, ft_strchr(s, '%') - s);
				flags->ret += ft_strchr(s, '%') - s;
				s = ft_strchr(s, '%');
			}
			else
			{
				buf = ft_memjoin(buf, s, flags->ret);
				flags->ret += ft_strlen(s);
				return (buf);
			}
		}
		if (*s && *s == '%')
		{
			s++;
			s = ft_grep_all(s, flags, ap);
			ptr_tab[(int)flags->conversion](flags);
			if (flags->ret == -1)
				return (NULL);
			if (flags->edited)
				buf = ft_memnjoin(buf, flags->edited, flags->ret, flags->malloc_len);
			flags->ret += flags->malloc_len;
		}
	}
	return (buf);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list ap;
	char	*buf;
	void	(*ptr_tab[128])(t_flags*);
	t_flags	*flags;
	int		ret;

	if ((ft_strlen(format) == 0) || ft_strlen(format) == 1 && format[0] == '%')
		return (0);
	flags = (t_flags*)malloc(sizeof(t_flags));
	ft_init_fctptr_table(ptr_tab);
	flags->ret = 0;
	va_start(ap, format);
	if ((!(buf = ft_strparse((char*)format, &ap, ptr_tab, flags))))
		return (-1);
	ft_reset_struct(flags, ap);
	ret = flags->ret;
	free(flags);
	write(1, buf, flags->ret);
	ft_strdel(&buf);
	va_end(ap);
	return (ret);
}
