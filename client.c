/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:01:53 by gyumpark          #+#    #+#             */
/*   Updated: 2022/05/25 16:12:31 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	my_kill(int s_pid, char *s)
{
	int		i;	

	i = 7;
	while (*s)
	{
		i = 7;
		while (i >= 0)
		{
			if (*s >> i & 1)
				kill(s_pid, SIGUSR1);
			else
				kill(s_pid, SIGUSR2);
			usleep(100);
			i--;
		}
		s++;
	}
}

int	main(int ac, char *av[])
{
	if (ac != 3)
	{
		write(1, "ERROR: input != 3", 17);
		exit(0);
	}
	my_kill(atoi(av[1]), av[2]);
}
