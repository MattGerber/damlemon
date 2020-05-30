#include "../includes/visualiser.h"

int	v_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	neg;

	i = 0;
	neg = 1;
	nbr = 0;
	while ((str[i] == '\t') || (str[i] == '\r') || (str[i] == '\f')\
		|| (str[i] == '\v') || (str[i] == ' ') || (str[i] == '\n'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		if (str[i++] == '-')
			neg = -1;
	while(!ft_isdigit(str[i]))
		i++;
	while (ft_isdigit(str[i]))
		nbr = (nbr * 10) + str[i++] - 48;
	return (nbr * neg);
}