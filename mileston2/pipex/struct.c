/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:55:40 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/02/27 19:11:35 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cleancmdpaths(char **cmd_paths)
{
	int	i;

	i = 0;
	while (cmd_paths[i])
	{
		free(cmd_paths[i]);
		i++;
	}
	free(cmd_paths);
	cmd_paths = NULL;
}

void	ft_cleanargs(char ***args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			free(args[i][j]);
			j++;
		}
		free(args[i]);
		args[i] = NULL;
		i++;
	}
	free(args);
	args = NULL;
}

void	*ft_cleanpipex(t_pipex *pipex)
{
	if (!pipex)
		return (NULL);
	if (pipex->cmd_paths)
		ft_cleancmdpaths(pipex->cmd_paths);
	if (pipex->args)
		ft_cleanargs(pipex->args);
	free(pipex);
	return (pipex = NULL);
}

t_pipex	*ft_newpipex(void)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->cmd_paths = (char **)malloc(sizeof(char *));
	if (!pipex->cmd_paths)
		return (ft_cleanpipex(pipex));
	pipex->args = (char ***)malloc(sizeof(char **));
	if (!pipex->args)
		return (ft_cleanpipex(pipex));
	pipex->in = 0;
	pipex->out = 0;
	return (pipex);
}
