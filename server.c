/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:35:35 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/16 16:27:48 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static	void	ft_putnubr(int c)
{
	if (c < 10)
	{
		c = (48 + c);
		write(1, &c, 1);
		return ;
	}
	ft_putnubr(c / 10);
	ft_putnubr(c % 10);
}

static	void	ft_handler(int nbr)
{
	static int	c = 0;
	static int	base = 128;

	if (nbr == SIGUSR1)
	{
		c += base;
		base /= 2;
	}
	else if (nbr == SIGUSR2)
		base /= 2;
	if (base == 0)
	{
		if (c == 255)
		{
			c = 0;
			base = 128;
		}
		else
			write(1, &c, 1);
		c = 0;
		base = 128;
	}
}

int	main(void)
{
	int	pid;

	pid = 0;
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
	{
		if (pid == 0)
		{
			pid = getpid();
			ft_putnubr(pid);
			write(1, "\n", 1);
		}
		pause();
	}
}
