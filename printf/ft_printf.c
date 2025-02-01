/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:44:28 by haboucha          #+#    #+#             */
/*   Updated: 2024/11/28 08:39:10 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkformat(const char *format, va_list str, int i)
{
	int	count;

	count = 0;
	if (format[i] == '%' && format[i + 1] == 's')
		count += ft_putstr(va_arg(str, char *));
	else if (format[i] == '%' && format[i + 1] == 'c')
		count += ft_putchar(va_arg(str, int));
	else if ((format[i] == '%') && (format[i + 1] == 'd' 
			|| format[i + 1] == 'i'))
		count += ft_putnbr_fd(va_arg(str, int));
	else if (format[i] == '%' && format[i + 1] == 'u')
		count += ft_putnbruns(va_arg(str, unsigned int));
	else if (format[i] == '%' && format[i + 1] == 'x')
		count += ft_hexa_lower(va_arg(str, unsigned int));
	else if (format[i] == '%' && format[i + 1] == '%')
		count += write(1, "%", 1);
	else if (format[i] == '%' && format[i + 1] == 'X')
		count += ft_hexa_upper(va_arg(str, unsigned int));
	else if (format[i] == '%' && format[i + 1] == 'p')
		count += write(1, "0x", 2) + ft_hexa_lower(va_arg(str, unsigned long));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	str;
	int		i;
	int		res;

	if (write(1, NULL, 0) < 0)
		return (-1);
	va_start(str, format);
	i = 0;
	res = 0;
	while (format[i] && (format[i] != '%' || format[i + 1] != '\0'))
	{
		if (format[i] == '%')
		{
			res += checkformat(format, str, i);
			i += 2;
		}
		else
		{
			res += write(1, &format[i], 1);
			i++;
		}
	}
	return (res);
}
