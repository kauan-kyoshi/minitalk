/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakubo-l <kakubo-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:53:30 by kakubo-l          #+#    #+#             */
/*   Updated: 2025/11/17 15:39:47 by kakubo-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static t_state	g_state = {0, 0, 0};

static void	process_full_byte(pid_t sender)
{
	unsigned char	c;

	if (g_state.current_char == 0)
	{
		write(1, "\n", 1);
		kill(sender, COMPLETE_ACK);
		g_state.client_pid = 0;
	}
	else
	{
		c = (unsigned char)g_state.current_char;
		write(1, &c, 1);
	}
	g_state.current_char = 0;
	g_state.bit_count = 0;
}

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	pid_t	sender;

	(void)ucontext;
	sender = info->si_pid;
	if (g_state.client_pid == 0)
		g_state.client_pid = sender;
	if (sender != g_state.client_pid)
	{
		g_state.current_char = 0;
		g_state.bit_count = 0;
		g_state.client_pid = sender;
	}
	if (sig == BIT_1)
		g_state.current_char = (g_state.current_char << 1) | 1;
	else
		g_state.current_char = (g_state.current_char << 1);
	g_state.bit_count++;
	if (g_state.bit_count == 8)
		process_full_byte(sender);
	kill(sender, ACK_SIGNAL);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		write(1, "sigaction error\n", 17);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		write(1, "sigaction error\n", 17);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		;
	return (0);
}
