/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:16:58 by fconde-p          #+#    #+#             */
/*   Updated: 2025/10/20 21:27:43 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define _POSIX_C_SOURCE 200809L // review aproach
#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

#include <unistd.h>

volatile sig_atomic_t	server_ready;

static void	client_sig_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if(signum == SIGUSR2)
	{
		server_ready = 1;
		// ft_printf("sig received!\n");
	} else if(signum == SIGUSR1)
	{
		ft_printf("SERVER ERROR!");
		exit(1);
	}
}

static void	send_bin_char(int pid, char c)
{
	int	i;
	int	bits;
	
	bits = 7;
	i = 0;
	while(i <= bits)
	{
		server_ready = 0;
		if(((c >> (bits - i)) & 1) == 1)
		{
			ft_printf("signal sent!\n");
			kill(pid, SIGUSR2);
		} else
		{
			ft_printf("signal sent!\n");
			kill(pid, SIGUSR1);
		}
		while(server_ready == 0)
			bits = 7;
		i++;
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
	// send_msg(pid, av[2]);
	while(*av[2] != '\0')
	{
		send_bin_char(pid, *av[2]);
		av[2]++;
	}
	return (0);
}