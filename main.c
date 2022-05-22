#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(int ac, char *av[])
{
	printf("%d %d\n", SIGUSR1, SIGUSR2);
}
