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
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while(1)
	{
		pause();
	}
	//signal(SIGUSR2, handler);
}
