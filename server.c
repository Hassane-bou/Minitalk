/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:16:05 by haboucha          #+#    #+#             */
/*   Updated: 2025/02/15 08:39:19 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	gerer_signales(int signe, siginfo_t *inf, void *p)
{
	static int	pid;
	static int	bit_count;
	static char	stocker;

	(void)p;
	if (pid != inf->si_pid)
	{
		bit_count = 0;
		stocker = 0;
	}
	pid = inf->si_pid;
	if (signe == SIGUSR1)
		stocker = (stocker << 1) | 1;
	else if (signe == SIGUSR2)
		stocker = (stocker << 1) | 0;
	bit_count++;
	if (bit_count == 8)
	{
		if (stocker == '\0')
		{
			ft_printf("\n");
			// ft_printf("%d\n",pid);
		}
		else
			ft_printf("%c", stocker);
		bit_count = 0;
		stocker = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Erreur\n");
		return (1);
	}
	ft_printf("PID:%d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = gerer_signales;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
