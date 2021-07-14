#ifndef MINITALK_HEADER_H
# define MINITALK_HEADER_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <inttypes.h>

char	*ft_itoa(int nb);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
int		isnumber(char *number);

#endif