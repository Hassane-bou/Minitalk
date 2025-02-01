/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:38:44 by haboucha          #+#    #+#             */
/*   Updated: 2024/11/27 11:39:35 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr_fd(int n);
int	ft_putnbruns(unsigned int n);
int	ft_hexa_upper(unsigned long nb);
int	ft_hexa_lower(unsigned long nb);

#endif