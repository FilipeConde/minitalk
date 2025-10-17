/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:16:58 by fconde-p          #+#    #+#             */
/*   Updated: 2025/10/17 19:04:52 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define _POSIX_C_SOURCE 200809L // review aproach
#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

#include <unistd.h>

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if(signum == SIGUSR2)
	{
		// keep sending
	} else if(signum == SIGUSR2)
	{
		// error
	}
}

int	main(int ac, char *av[])
{
	pid_t				pid;
	struct sigaction	sa;
	int					i;

	i = 0;
	pid = ft_atoi(av[1]);
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask); // review aproach
	sa.sa_flags = SA_SIGINFO; // review aproach
	// pid = 0;

	if(sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if(sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
		
	(void)ac;
	while (av[2])
	{
		kill(pid, SIGUSR2);
		ft_printf("%c\n", av[2]);
		av[2]++;
	}

}