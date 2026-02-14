/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnayel <hnayel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:55:43 by hnayel            #+#    #+#             */
/*   Updated: 2026/02/14 20:30:31 by hnayel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	usage(void)
{
	ft_putstr("Usage: ./client <PID> <Message>\n");
	return (-1);
}

static void	send_char(int pid, unsigned char c)
{
	int	i;
	
	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(800);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
		return (usage());
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (-1);
	while (av[2][i])
		send_char(pid, av[2][i++]);
	usleep(800);
	send_char(pid, 0);
	return (0);
}