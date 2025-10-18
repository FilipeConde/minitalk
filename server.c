/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:46:35 by fconde-p          #+#    #+#             */
/*   Updated: 2025/10/18 19:59:27 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define _POSIX_C_SOURCE 200809L // review aproach
#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>

int	bit_count;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	static char	c;

	if(bit_count == 0)
		c = 0;
	if(signum == SIGUSR1)
	{
		// ft_printf("%d", 0);
		c = (c << 1);
		bit_count++;
		kill(info->si_pid, SIGUSR2);
	} else if(signum == SIGUSR2)
	{
		// ft_printf("%d", 1);
		c = (c << 1) | 1;
		bit_count++;
		kill(info->si_pid, SIGUSR2);
	} else
		kill(info->si_pid, SIGUSR1);
	if(bit_count == 7)
	{
		ft_printf("%c", c);
		bit_count = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;
	int					dumb;

	bit_count = 0;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask); // review aproach
	sa.sa_flags = SA_SIGINFO; // review aproach
	// pid = 0;

	if(sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if(sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);

	while(1)
	{
		// pause();
		// sleep(1);
		// usleep(100);
		dumb = 0;
	}
	return (0);
}