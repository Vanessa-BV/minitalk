/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:09:18 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/04/10 16:09:18 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "Libft/libft.h"

void	exit_with_error(char *error_message, char *str_to_free)
{
	ft_putstr_fd(error_message, 2);
	if (str_to_free != NULL)
		free(str_to_free);
	exit(EXIT_FAILURE);
}

char	*create_string(char *str, unsigned char c)
{
	char	*temp;
	char	*string;

	if (str == NULL)
	{
		str = ft_strdup("");
		if (str == NULL)
			exit_with_error("Error: Could not allocate memory\n", NULL);
	}
	temp = str;
	string = ft_strjoin_c(temp, c);
	free(temp);
	if (string == NULL)
		exit_with_error("Error: Could not allocate memory\n", str);
	return (string);
}

int	set_next_bit(int num, int bit)
{
	return (num << 1 | bit);
}

void	handler(int signal, siginfo_t *info, void *ucontext)
{
	static int				count = 0;
	static unsigned char	c = '\0';
	static char				*string = NULL;

	(void)ucontext;
	if (signal == SIGUSR1)
		c = set_next_bit(c, 0);
	else if (signal == SIGUSR2)
		c = set_next_bit(c, 1);
	count++;
	if (count == 8)
	{
		string = create_string(string, c);
		count = 0;
		if (c == '\0')
		{
			ft_putstr_fd(string, 1);
			free(string);
			string = NULL;
		}
	}
	if (kill(info->si_pid, SIGUSR2) == -1)
		exit_with_error("Error: Could not send signal\n", string);
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("Server PID: %d\n", getpid());
	if (sigemptyset(&action.sa_mask) == -1)
		exit_with_error("Error: Could not initialize an \
		empty signal set.\n", NULL);
	action.sa_flags = SA_SIGINFO | SA_NODEFER;
	action.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &action, NULL) == -1 || \
	sigaction(SIGUSR2, &action, NULL) == -1)
		exit_with_error("Error: Could not set signal handler\n", NULL);
	while (1)
		pause();
	return (0);
}
