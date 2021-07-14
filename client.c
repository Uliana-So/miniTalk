#include "minitalk_header.h"

void	handler_message(char *str, int pid)
{
	int	i;
	int n;
	// struct siginfo_t	si_return;

	i = 0;
	while (str[i] != '\0')
	{
		n = 0;
		while (n < 8)
		{
			if ((str[i] >> n) & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
				{
					write(1, "CANNOT SEND SIGNAL\n", 20);
					return ;
				}
				printf("12 ");
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
				{
					write(1, "CANNOT SEND SIGNAL\n", 20);
					return ;
				}
				printf("10 ");
			}		
			n++;
			// printf("", si_pid);
			usleep(1000);
		}
		printf("\n%c %d", str[i], str[i]);
		// printf("   %c\n", str[i]);
		// send_char(str[i - 1], pid);
		i++;
		printf("\n");
	}
	printf("n - > %d\n", n);
	// while (n > 0)
	// {
	// 	if (kill(pid, SIGUSR1) == -1)
	// 	{
	// 		write(1, "CANNOT SEND SIGNAL\n", 20);
	// 		return ;
	// 	}
	// 	n--;
	// 	usleep(500);
	// }
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		write(1, "WRONG ARGS\n", 11);
	else
	{
		pid = isnumber(argv[1]);
		if (pid != 0)
			handler_message(argv[2], pid);
		else
			write(1, "WRONG PID\n", 10);
	}
	exit (0);
}