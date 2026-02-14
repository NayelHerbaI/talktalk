/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnayel <hnayel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:55:43 by hnayel            #+#    #+#             */
/*   Updated: 2026/02/14 19:12:16 by hnayel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	usage(void)
{
	ft_putstr("Usage: ./client <PID> <Message>\n");
	return (-1);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ac != 3)
		return (usage());
	return (0);
}