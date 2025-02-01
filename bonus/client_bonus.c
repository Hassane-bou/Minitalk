/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:47:01 by haboucha          #+#    #+#             */
/*   Updated: 2025/02/01 12:14:41 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	s;

	s = 1;
	i = 0;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * s);
}

void	message_confirm(int signe)
{
	if (signe == SIGUSR2)
		ft_printf("Message envoyer avec succes\n");
}

void	char_to_binary(int PID, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		i;
	char	*message;
	int		pid;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Usage: ./client <PID> <Message>\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("PID_INVALID\n");
		return (1);
	}
	message = av[2];
	signal(SIGUSR2, message_confirm);
	if (ac == 3)
	{
		while (message[i])
			char_to_binary(pid, message[i++]);
	}
	char_to_binary(pid, '\0');
	return (0);
}
