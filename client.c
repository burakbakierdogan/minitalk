/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:35:18 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/16 16:26:27 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static	int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}
static	int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static	int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	unsigned long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (*nptr == '\0')
		return (0);
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		res = (res * 10) + (nptr[i++] - '0');
	if (res > LONG_MAX && sign == -1)
		return (0);
	if (res > LONG_MAX && sign == 1)
		return (-1);
	return (res * sign);
}

void	ft_convert(int c, char *str, int my_index)
{
	int	i;

	i = my_index + 7;
	while (c > 0)
	{
		str[i--] = (char)((c % 2) + 48);
		c /= 2;
	}
	while (i >= my_index)
		str[i--] = '0';
}

static	void	ft_send_signal(char *str, int my_index, int pid)
{
	int	i;

	i = 0;
	while (i <= my_index)
	{
		if (str[i] == '1')
			kill (pid, SIGUSR1);
		if (str[i] == '0')
			kill (pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

int	main(int ac, char *argv[])
{
	int		pid;
	char	*str;
	int		i;
	int		my_index;

	my_index = 0;
	if (ac == 3)
	{
		pid = ft_atoi(argv[1]);
		str = malloc ((1024 * 8) * sizeof(char));
		if (!str)
			return (-1);
		i = 0;
		while (argv[2][i])
		{
			ft_convert((int)argv[2][i++], str, my_index);
			my_index += 8;
		}
		ft_convert(255, str, my_index);
		ft_send_signal(str, my_index + 8, pid);
		free(str);
	}
	return (0);
}
