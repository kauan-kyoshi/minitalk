/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakubo-l <kakubo-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:16:05 by kakubo-l          #+#    #+#             */
/*   Updated: 2025/11/14 17:27:43 by kakubo-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE 200809L
# endif

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdint.h>
# include "libft.h"

typedef struct s_state
{
	volatile sig_atomic_t	client_pid;
	volatile sig_atomic_t	current_char;
	volatile sig_atomic_t	bit_count;
}		t_state;

# define BIT_0 SIGUSR1
# define BIT_1 SIGUSR2
# define ACK_SIGNAL SIGUSR1
# define COMPLETE_ACK SIGUSR2

int		usleep(useconds_t usec);

void	error_exit(char *msg, int code);

#endif
