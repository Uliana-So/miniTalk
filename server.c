#include "minitalk_header.h"

int	power_of_two(int n)
{
	int	res;

	res = 1;
	while (n > 0)
	{
		res*=2;
		n--;
	}
	// printf("return -> %d\n", res);
	return (res);
}

void	print_char(char *str)
{
	int		res;
	char	c;

	// printf("str %s\n", str);                     // STRLEN
	res = ((str[0] - '0') * power_of_two(6))
	+ ((str[1] - '0') * power_of_two(5))
	+ ((str[2] - '0') * power_of_two(4))
	+ ((str[3] - '0') * power_of_two(3))
	+ ((str[4] - '0') * power_of_two(2))
	+ ((str[5] - '0') * power_of_two(1))
	+ ((str[6] - '0') * power_of_two(0));
	c = res;
	// printf("-> %c %d\n\n", c, res);
	write(1, &c, 1);
}

void	handler_server(int n)
{
	static char	num[7];
	static int	i = 0;

	// printf("%d %d\n", n, i);
	if (n == 10) // 30
		num[i] = '0';
	else if (n == 12)  // 31
		num[i] = '1';
	i++;
	if (i == 7)
	{
		i = 0;
		print_char(num);
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
