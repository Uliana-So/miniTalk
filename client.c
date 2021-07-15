#include "minitalk_header.h"

int	send_byte(char symbol, int pid)
{
	int	n;

	n = 0;
	while (n < 8)
	{
		if ((symbol >> n) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, RED "CANNOT SEND SIGNAL\n" RESET, 31);
				return (0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, RED "CANNOT SEND SIGNAL\n" RESET, 31);
				return (0);
			}
		}
		usleep(40);
		n++;
	}
	return (1);
}

void	handler_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (1)
	{
		if (!send_byte(str[i], pid) || str[i] == '\0')
			break ;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		write(1, RED "WRONG ARGS\n" RESET, 22);
	else
	{
		pid = isnumber(argv[1]);
		if (pid != 0)
			handler_message(argv[2], pid);
		else
			write(1, RED "WRONG PID\n" RESET, 21);
	}
	exit (0);
}
