/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:31:08 by haboucha          #+#    #+#             */
/*   Updated: 2024/11/27 11:49:48 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_lower(unsigned long nb)
{
	char	c;
	int		count;
	char	*hexa;

	hexa = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
	{
		count += ft_hexa_lower(nb / 16);
		c = hexa[(nb % 16)];
		write(1, &c, 1);
		count++;
	}
	else
	{
		c = hexa[(nb % 16)];
		write(1, &c, 1);
		count++;
	}
	return (count);
}

int	ft_hexa_upper(unsigned long nb)
{
	char	d;
	int		len;
	char	*hexa;

	hexa = "0123456789ABCDEF";
	len = 0;
	if (nb >= 16)
	{
		len += ft_hexa_upper(nb / 16);
		d = hexa[(nb % 16)];
		write(1, &d, 1);
		len++;
	}
	else
	{
		d = hexa[(nb % 16)];
		write(1, &d, 1);
		len++;
	}
	return (len);
}
