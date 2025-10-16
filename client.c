/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:16:58 by fconde-p          #+#    #+#             */
/*   Updated: 2025/10/16 19:05:22 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define _POSIX_C_SOURCE 200809L // review aproach
#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

#include <unistd.h>

// receives PID and message to be sent
int	main(int ac, char *av[])
{
	int	pid;
	int	i;

	i = 0;
	pid = ft_atoi(av[1]);
	(void)ac;
	while (i <= 3)
	{
		kill(pid, SIGUSR2);
		i++;
		ft_printf("%d\n", pid);
	}

}