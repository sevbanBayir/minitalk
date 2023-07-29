/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayir <sbayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:56:18 by sbayir            #+#    #+#             */
/*   Updated: 2023/07/29 11:28:00 by sbayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *string)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (*(string + i))
	{
		result *= 10;
		result += (*(string + i) - '0');
		i++;
	}
	return (result);
}

void	send_signal(char *message, pid_t server_pid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (message[i]) 
	{
		c = message[i];
		j = 0;
		while (j < 7) 
		{
			if (c & (1 << j))
				kill (server_pid, SIGUSR2);
			else
				kill (server_pid, SIGUSR1);
			usleep (100);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Usage: ./client <server_pid> \"message to send\" \n");
		return (1);
	}
	if (ft_atoi(argv[1]) < 0)
	{
		ft_printf("Please enter a valid PID");
		return (1);
	}
	send_signal(argv[2], ft_atoi(argv[1]));
	return (0);
}
