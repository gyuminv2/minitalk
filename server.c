/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:03:59 by gyumpark          #+#    #+#             */
/*   Updated: 2022/05/22 21:55:30 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	talk(int sig)
{
	static int	byte;
	static int	space;

	space = 7;
	if (sig == SIGUSR1)
		byte += 1 << --space;
	//else if (sig == SIGUSR2)
	//	--space;
	--space;
	if (space == 0)
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

int main()
{
	write(1, "SERVER PID: ", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, talk);
	signal(SIGUSR2, talk);
	while(1)
	{
		pause();
	}
}
