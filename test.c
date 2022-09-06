#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void sighup();
void sigint();
void sigquit();

void main()
{
	int pid;

	if ((pid = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		signal (SIGHUP, sighup);
		signal (SIGINT, sigint);
		signal (SIGQUIT, sigquit);
		for (;;)
			;
	}
	else
	{
		parent ("\nsending SIGHUP\n\n");
		kill(pid, SIGHUP);
		sleep(3);
		printf("\nPARENT: sending SIGUP\n\n");
		kill(pid, SIGINT);
		sleep(3);
		printf("\nPARENT:sending SIGINT\n\n");
		kill(pid, SIGINT);
		sleep(3);
		printf("\nPARENT: sending SIGQUIT\n\n");
		kill(pid, SIGQUIT);
		sleep(3);
	}
}
void sighup()
{
	signal (SIGNUP, sighup); /* reset signal */
	printf("CHILD: I have received a SIGHUP\n");
}
void signint()
{
	signal(SIGINT, sigint);
	printf("CHILD: I have received a SIGINT\n");
}
void sigquit()
{
	printf("My DADDY has killed me!!!\n");
	exit(0);
}
