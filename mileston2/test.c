/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:52:52 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/02/27 13:09:36 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(/* int argc, char **argv */)
{
	char	*cmd1[3];
	char	*cmd2[3];
	pid_t	pid;
	int		fd[2];
	char	buffer[5];

	cmd1[0] = "echo";
	cmd1[1] = "hola";
	cmd1[2] = NULL;
	cmd2[0] = "wc";
	cmd2[1] = "-c";
	cmd2[2] = NULL;
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve("/bin/echo", cmd1, NULL);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		execve("/bin/wc", cmd2, NULL);
		exit(EXIT_SUCCESS);
	}
}
