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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_lennumber(long long int n)
{
	int				i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	ft_creatstr(char **res_s, long long int n, int i)
{
	char	*res;

	res = *res_s;
	res[i] = '\0';
	if (n < 10)
		res[i - 1] = n + '0';
	while (n > 0)
	{
		res[i - 1] = n % 10 + '0';
		n /= 10;
		i--;
	}
	if (res[0] == '\0')
		res[0] = '-';
}

char	*ft_itoa(int nb)
{
	char			*res;
	int				i;
	long long int	n;

	n = nb;
	res = 0;
	i = 0;
	if (n < 0)
	{
		n *= -1;
		i = 1;
	}
	i += ft_lennumber(n);
	res = (char *)malloc(i + 1);
	if (res)
		ft_creatstr(&res, n, i);
	return (res);
}
