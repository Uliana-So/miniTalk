#include "minitalk_header.h"

void	send_char(char c, int pid)
{
	char	str[7];
	int		i;
	int		ch;

	i = 0;
	ch = c;
	// printf("here send %d %c %d\n", ch, c, c);
	while (i < 7)
	{
		// printf("%d\n", i);
		str[i] = (ch % 2) + '0';
		ch = ch / 2;
		i++;
	}
	// str[i] = '\0';
	// printf("str %s\n", str);
	// i = ft_strlen(str);
	// i = 8;
	i--;
	printf("rev ");
	while (i > -1)
	{
		printf("%c", str[i]);
		if (str[i] == '0')
			kill(pid, SIGUSR1);
		else if (str[i] == '1')
			kill(pid, SIGUSR2);
		// printf("%c", str[i]);
		usleep(100);
		i--;
	}
	printf("\n\n");
}

void	handler_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		// printf("%c\n", str[i]);
		send_char(str[i], pid);
		i++;
	}
	send_char('\n', pid);
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