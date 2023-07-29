/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayir <sbayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:06:33 by sbayir            #+#    #+#             */
/*   Updated: 2023/07/22 16:06:57 by sbayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdarg.h>

struct s_character {
	char	character;
	int		current_bit;
};

int		ft_atoi(char *string);
int		ft_printf(const char *s, ...);
void	ft_send_signal(char *str, int pid);
void	ft_check(va_list *list, char a, int *result);
void	ft_putnbr(int n, int *result);
void	ft_putstr(char *s, int *result);
void	ft_putchar(char c, int *result);

#endif
