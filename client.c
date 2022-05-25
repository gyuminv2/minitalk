/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:01:53 by gyumpark          #+#    #+#             */
/*   Updated: 2022/05/22 21:55:29 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	my_kill(int s_pid, char *s)
{
	char	save;
	int		i;	
	int		j;

	i = 7;
	j = 0;
	while (*s)
	{
		while (i >= 0)
		{
			if (*s >> i & 1)
				kill(s_pid, SIGUSR1); //	1
			else
				kill(s_pid, SIGUSR2); //	0
			usleep(100);
			i--;
		}
		s++;
	}
}

int main(int ac, char *av[]) // av[1] = server_pid, av[2] = 문자열
{
	//kill(atoi(av[1]), atoi(av[2]));
	printf("%d %d\n", atoi(av[1]), atoi(av[2]));
	my_kill(atoi(av[1]), av[2]);
}
