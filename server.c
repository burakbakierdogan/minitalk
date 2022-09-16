/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:35:35 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/15 23:35:35 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_index = 0;
char *str;
int	c = 1;
int	base = 1;

/*
static	void	ft_write(char *str, int	my_index)
{
	int	i;
	int	j;
	int	c;
	int	base;

	i = 0;
	my_index -= 8;
	j = 0;
	c = 0;
	base = 1;
	while (i <= my_index)
	{
		while (j < 8 && i <= my_index)
		{
			c += (str[i++] - 48) * base;
			base *= 2;
			j++;
		}
		write(1, &c, 1);
		j = 0;
		c = 0;
	}
	my_index = 0;
}
*/
/*
static	int	ft_stop(char *str, int my_index)
{
	int	i;
	int	j;
	int	total;

	i = my_index;
	j = i - 8;
	total = 0;
	while(i > j)
	{
		if (str[i] == '1')
			total++;
		else
			break ;
		i--;
	}
	if (total == 7)
		return (1);
	return (0);
}
*/
void	ft_handler(int nbr)
{
	static	int	c = 0;
	static	int	base = 128;

	if (nbr == 10)
	{
		c += base;
		base /= 2;
	}
	else if (nbr == 12)
		base /= 2;
	if (base == 0)
	{
		if (c == 255)
			write (1, "\n", 1);
		else
		write(1, &c, 1);
		c = 0;
		base = 128;
	}


}

int	main()
{
	int	pid;
	int n =0;

	str = malloc (100000);
	pid = getpid();
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
	{
		if(n == 0)
		printf("%d\n", pid);
		n++;
		pause();
	}

}
