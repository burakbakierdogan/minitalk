/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:45:57 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/06 19:11:43 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "printf.h"
#include "libft.h"

int	main(int ac, char *argv[])
{
	int	pid;

	pid = getpid();
	printf("%d\n", pid);
}
