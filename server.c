/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:46:35 by fconde-p          #+#    #+#             */
/*   Updated: 2025/10/15 19:07:29 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define _POSIX_C_SOURCE 200809L // review aproach
#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	ft_printf("SIG HANDLER ACCESSED: val => %d\n", signum);
	kill(info->si_pid, 1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

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
		sleep(1);
		// or usleep(100);
	}
	return (0);
}