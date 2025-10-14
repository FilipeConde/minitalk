/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:46:35 by fconde-p          #+#    #+#             */
/*   Updated: 2025/10/13 21:51:38 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define _POSIX_C_SOURCE 200809L
#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>

void	signal_handler(int sigchannel, siginfo_t *info)
{
	ft_printf("SIG HANDLER ACCESSED: val => %d\n", sigchannel);
}

int	server(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	pid = 0;
	pid = getpid();
	ft_printf("%d", pid);

	while(1)
	{
		sleep(1);
	}
	return (pid);
}

int	main(void)
{
	server();
}