#include "minitalk_header.h"

void	handler_server(int n)
{
	static char	num;
	static int	i = 0;

	if (n == 30)
		num = num & ~(1 << i);
	else if (n == 31)
		num = num | (1 << i);
	i++;
	if (i == 8)
	{
		i = 0;
		if (num == 0)
			write(1, "\n", 1);
		else
			write(1, &num, 1);
	}
}

int	main(void)
{
	pid_t	pid;
	char	*pid_char;

	signal(SIGUSR1, handler_server);
	signal(SIGUSR2, handler_server);
	pid = getpid();
	pid_char = ft_itoa(pid);
	write(1, YELLOW "PID " RESET, 15);
	write(1, pid_char, ft_strlen(pid_char));
	write(1, "\n", 1);
	free(pid_char);
	while (1)
		pause();
	return (0);
}
