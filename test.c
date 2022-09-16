/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:35:24 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/15 23:35:24 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void	handler(int b)
{

}
int main()
{

	char *str;
	int c = 97;

	str = malloc (10);
	str[8] = (c % 2) + 48;
	c /= 2;
	str[7] = (c % 2) + 48;
	printf("%c - %c\n",str[8], str[7]);
}
