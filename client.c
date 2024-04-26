/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:09:12 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/04/10 16:09:12 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "Libft/libft.h"

int	g_server_confirmed = 0;

void	exit_with_error(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void	server_got_signal(int sig)
{
	if (sig == SIGUSR2)
		g_server_confirmed = 1;
}

void	send_byte(char byte, int pid)
{
	int	shift;
	int	kill_return;
	int	i;

	shift = 7;
	while (shift >= 0)
	{
		i = 0;
		g_server_confirmed = 0;
		if ((byte >> shift & 1) == 0)
			kill_return = kill(pid, SIGUSR1);
		else
			kill_return = kill(pid, SIGUSR2);
		if (kill_return == -1)
			exit_with_error("Error: PID is invalid.\n");
		shift--;
		while (i++ < 100000 && g_server_confirmed == 0)
			usleep(10);
		if (i == 100000)
			exit_with_error("Error: Server did not respond.\n");
	}
}

int	main(int argc, char **argv)
{
	int			pid;
	int			i;

	if (argc != 3)
		exit_with_error("./client [pid of server] [string]\n");
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		exit_with_error("Error: Invalid PID.\n");
	if (signal(SIGUSR2, server_got_signal) == SIG_ERR)
		exit_with_error("Error: Could not set signal handler.\n");
	while (argv[2][i] != '\0')
	{
		send_byte(argv[2][i], pid);
		i++;
	}
	send_byte('\0', pid);
	if (g_server_confirmed == 1)
		ft_printf("Signal received back from server.\n");
	return (0);
}
