/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:03:59 by gyumpark          #+#    #+#             */
/*   Updated: 2022/05/25 16:14:02 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	talk(int sig)
{
	static char	byte;
	static int	space;

	if (sig == SIGUSR1)
		byte += 1 << (7 - space);
	if (sig == SIGUSR2)
		space++;
	else
		space++;
	if (space == 8)
	{
		write(1, &byte, 1);
		byte = 0;
		space = 0;
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "RECEIVE SIGUSR1", 16);
	}
	else if (sig == SIGUSR2)
	{
		write(1, "RECEIVE SIGUSR2", 16);
	}
}

int	main(void)
{
	write(1, "SERVER PID: ", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, talk);
		signal(SIGUSR2, talk);
		pause();
	}
}
