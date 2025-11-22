/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakubo-l <kakubo-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:53:19 by kakubo-l          #+#    #+#             */
/*   Updated: 2025/11/17 15:39:35 by kakubo-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ACK-enabled client: sends bits MSB-first and waits for server ack per bit.
 * BIT_0 = SIGUSR1, BIT_1 = SIGUSR2, ACK_SIGNAL = SIGUSR1
 */

#include "includes/minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

static volatile sig_atomic_t	g_ack_count = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	g_ack_count++;
}

static int	send_char(pid_t server_pid, unsigned char c)
{
	int	cur_count;
	int	i;

	i = 7;
	while (i >= 0)
	{
		cur_count = g_ack_count;
		if (((c >> i) & 1) == 1)
		{
			if (kill(server_pid, BIT_1) == -1)
				return (-1);
		}
		else
		{
			if (kill(server_pid, BIT_0) == -1)
				return (-1);
		}
		while (g_ack_count == cur_count)
			pause();
		i--;
	}
	return (0);
}

static int	parse_args(int argc, char **argv, pid_t *server_pid)
{
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	*server_pid = (pid_t)ft_atoi(argv[1]);
	if (*server_pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = ack_handler;
	if (sigaction(ACK_SIGNAL, &sa, NULL) == -1)
		return (1);
	if (sigaction(COMPLETE_ACK, &sa, NULL) == -1)
		return (1);
	return (0);
}

static int	send_terminator_and_wait(pid_t server_pid)
{
	int	prev;
	int	waited;

	prev = g_ack_count;
	if (send_char(server_pid, '\0') == -1)
		return (-1);
	waited = 0;
	while (g_ack_count < prev + 9 && waited < 2000)
	{
		usleep(1000);
		waited++;
	}
	if (g_ack_count >= prev + 9)
		ft_printf("Done\n");
	else
		ft_printf("No completion ACK (timeout)\n");
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	size_t	i;

	if (parse_args(argc, argv, &server_pid) != 0)
		return (1);
	i = 0;
	while (argv[2][i])
	{
		if (send_char(server_pid, (unsigned char)argv[2][i]) == -1)
		{
			ft_printf("Failed to send to server\n");
			return (1);
		}
		i++;
	}
	if (send_terminator_and_wait(server_pid) == -1)
	{
		ft_printf("Failed to send terminator\n");
		return (1);
	}
	return (0);
}
