#include "minitalk_header.h"

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
