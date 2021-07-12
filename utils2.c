#include "minitalk_header.h"

int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}

int	isnumber(char *number)
{
	int	i;
	int	res;

	i = 0;
	res = -1;
	while (number[i] != '\0')
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (ft_atoi(number));
}
