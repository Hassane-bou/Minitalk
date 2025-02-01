/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbruns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:50:19 by haboucha          #+#    #+#             */
/*   Updated: 2024/11/23 21:39:42 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_putnbruns(unsigned int n)
{
	char			c;
	long			d;
	unsigned int	i;

	i = ft_count(n);
	d = n;
	if (d > 9)
	{
		ft_putnbr_fd(d / 10);
		ft_putnbr_fd(d % 10);
	}
	else if (d >= 0 && d <= 9)
	{
		c = d + '0';
		write(1, &c, 1);
	}
	return (i);
}
