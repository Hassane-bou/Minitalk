/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:58:09 by haboucha          #+#    #+#             */
/*   Updated: 2024/11/23 21:17:01 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	else if (nb < 0)
	{
		nb *= -1;
		len = 1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_fd(int n)
{
	char	c;
	long	d;
	int		i;

	i = count(n);
	d = n;
	if (d == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (d < 0)
	{
		d *= -1;
		write(1, "-", 1);
		ft_putnbr_fd(d);
	}
	else if (d > 9)
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
