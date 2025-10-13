/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:46:35 by fconde-p          #+#    #+#             */
/*   Updated: 2025/10/13 20:40:08 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/types.h>
#include <unistd.h>
#include "libft/libft.h"

int	server(void)
{
	pid_t	pid;

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