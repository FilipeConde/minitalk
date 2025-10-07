/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:01:45 by fconde-p          #+#    #+#             */
/*   Updated: 2025/07/23 19:39:45 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*int	main(void)
{
	char	string[] = "Caso";
	int	lenght;
	char	c_lenght;

	lenght = ft_strlen(string);
	c_lenght = lenght + '0';
	write(1, &c_lenght, 1);
}*/
