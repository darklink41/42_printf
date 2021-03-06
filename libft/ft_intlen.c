/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:20:52 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/26 17:28:48 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_intlen(unsigned long long int i)
{
	int size;

	size = 1;
	while ((i / 10) > 0)
	{
		i /= 10;
		size += 1;
	}
	return (size);
}
