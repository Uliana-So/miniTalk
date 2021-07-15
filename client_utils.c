#include "minitalk_header.h"

int	ft_atoi(const char *str)
{
	int				i;
	long long int	result;
	int				minus;

	i = 0;
	result = 0;
	minus = 1;
	while (str[i] && ((str[i] > 7 && str[i] < 14) || str[i] == 32))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = 10 * result + (str[i] - '0') * minus;
		i++;
		if (result < 0 && minus > 0)
			return (-1);
		else if (result > 0 && minus < 0)
			return (0);
	}
	return (result);
}

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
