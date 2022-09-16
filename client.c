/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:35:18 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/15 23:35:18 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int ac, char *argv[])
{
	int		pid;
	char	*str;
	int		i;
	int		my_index = 0;

	if (ac == 3)
	{
		pid = atoi(argv[1]);
		str = malloc (90000 * sizeof(char));
		i = 0;
		while (argv[2][i])
		{
			ft_convert((int)argv[2][i++], str, my_index);
			my_index += 8;
		}
		ft_convert(255, str, my_index);
		i = 0;
		printf("%s\n", str);
		while(i <= my_index + 8)
		{
			if (str[i] == '1')
				kill (pid, SIGUSR1);
			if (str[i] == '0')
				kill (pid, SIGUSR2);
			i++;
			usleep(5000);
		}
		free(str);
	}
}
