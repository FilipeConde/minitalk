/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:46:35 by fconde-p          #+#    #+#             */
/*   Updated: 2025/10/13 22:19:10 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define _POSIX_C_SOURCE 200809L // review aproach
#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>

void	signal_handler(int sigchannel, siginfo_t *info, void *context)
{
	ft_printf("SIG HANDLER ACCESSED: val => %d\n", sigchannel);
	// put some response for client when received
}

// int	server(void)
// {
// 	pid_t				pid;
// 	struct sigaction	sa;

// 	sa.sa_handler = signal_handler;
// 	sigemptyset(&sa.sa_mask); // review aproach
// 	sa.sa_flags = SA_SIGINFO; // review aproach
// 	// pid = 0;
// 	pid = getpid();
// 	ft_printf("Server PID: %d\n", pid);

// 	while(1)
// 	{
// 		sleep(1);
// 	}
// 	return (0);
// }

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
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
		pause();
	}
	return (0);
}