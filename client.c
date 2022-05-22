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

void	my_kill(int s_pid, char *s)
{
	char	save;
	int		i;	

	i = 0;
	while (*s)
	{
		save = s[i];
		while (i > 7)
		{
			kill(s_pid, SIGUSR1);	//0
			kill(s_pid, SIGUSR2);	//1
		}
	}
}

int main(int ac, char *av[]) // av[1] = server_pid, av[2] = 문자열
{
	printf("client PID: %d\n", getpid());
	//kill(서버PID, 전송문자)
	my_kill(atoi(av[1]), av[2]);
	printf("%d %d\n", atoi(av[1]), atoi(av[2]));
}
