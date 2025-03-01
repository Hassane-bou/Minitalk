/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:47:01 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/01 18:21:46 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

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


void	char_to_binary(int PID, char c)
{
	int	i;
	int check;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			check = kill(PID, SIGUSR1);
		else
			check = kill(PID, SIGUSR2);
		if(check == -1){
			write(2, "hHHHH", 5);
			exit(1);
		}
			
		usleep(400);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		i;
	char	*message;
	int		pid;

	if (ac != 3)
	{
		ft_printf("Usage: ./client <PID> <Message>\n");
		return (1);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	while(av[1][i])
	{
		if (pid <= 0 || ((av[1][i] >= 58 && av[1][i] <= 126) || (av[1][i] >= 32 && av[1][i] <= 47) ))
		{
			ft_printf("PID_INVALID\n");
			return (1);
		}
	i++;
	}
	i =0;
	message = av[2];
	if (ac == 3)
	{
		while (message[i])
			char_to_binary(pid, message[i++]);
	}
	char_to_binary(pid, '\0');
	return (0);
}
