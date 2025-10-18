/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:16:58 by fconde-p          #+#    #+#             */
/*   Updated: 2025/10/17 21:41:43 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define _POSIX_C_SOURCE 200809L // review aproach
#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

#include <unistd.h>

int	server_ready;

void	client_sig_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if(signum == SIGUSR2)
	{
		server_ready = 1;
	} else if(signum == SIGUSR1)
	{
		ft_printf("SERVER ERROR!");
		exit(1);
	}
}

void	send_msg(int pid, char *s)
{
	while (*s)
	{
		server_ready = 0;
		ft_printf("%c\n", *s);
		kill(pid, SIGUSR2);
		s++;
		while (server_ready == 0)
		{
			sleep(1);
		}
	}
}

int	main(int ac, char *av[])
{
	pid_t				pid;
	struct sigaction	sa;
	int					i;

	i = 0;
	pid = ft_atoi(av[1]);
	sa.sa_sigaction = client_sig_handler;
	sigemptyset(&sa.sa_mask); // review aproach
	sa.sa_flags = SA_SIGINFO; // review aproach
	// pid = 0;

	if(sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if(sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
		
	(void)ac;
	send_msg(pid, av[2]);
	return (0);
}