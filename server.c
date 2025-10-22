/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:46:35 by fconde-p          #+#    #+#             */
/*   Updated: 2025/10/21 21:07:16 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # define _POSIX_C_SOURCE 200809L // review aproach
#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>

int	g_bit_count;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	c;

	(void)context;
	if (g_bit_count == 0)
		c = 0;
	if (signum == SIGUSR1)
	{
		c = (c << 1);
		g_bit_count++;
		kill(info->si_pid, SIGUSR2);
	}
	else if (signum == SIGUSR2)
	{
		c = (c << 1) | 1;
		g_bit_count++;
		kill(info->si_pid, SIGUSR2);
	}
	if (g_bit_count == 8)
	{
		ft_printf("%c", c);
		g_bit_count = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;
	int					dumb;

	g_bit_count = 0;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
		dumb = 0;
	return (0);
}
