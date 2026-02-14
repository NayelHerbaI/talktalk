/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnayel <hnayel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:55:39 by hnayel            #+#    #+#             */
/*   Updated: 2026/02/14 19:13:09 by hnayel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig)
{
	static int	bit;

	bit++;
	if (bit == 8)
	{
		ft_putstr("8 bits received\n");
		bit = 0;
	}
	if (sig == SIGUSR1)
		ft_putstr("SIGUSR1\n");
	if (sig == SIGUSR2)
		ft_putstr("SIGUSR2\n");
}

int	main(int ac, char **av)
{
	pid_t	pid;

	(void)ac;
	(void)av;
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
	}
	return (0);
}