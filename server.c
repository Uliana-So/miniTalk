#include "minitalk_header.h"

void	handler_server(int n)
{
	static char	num;
	static int	i = 0;

	// printf("%d %d ", n, i);
	if (n == 10) // 30
	{
		num = num & ~(1 << i);
		// printf("0\n");
	}
	else if (n == 12)
	{
		num = num | (1 << i);
		// printf("1\n");
	}
	i++;
	if (i == 8)
	{
		i = 0;
		// print_char(num);
		// printf("%d\n", num);
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
	write(1, "PID ", 4);
	write(1, pid_char, ft_strlen(pid_char));
	write(1, "\n", 1);
	free(pid_char);
	while (1)
		pause();
	return (0);
}
