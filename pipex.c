/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:40:37 by marianamest       #+#    #+#             */
/*   Updated: 2024/09/21 17:40:11 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	pipefd[2];
	int	pid;

	if (ac != 5)
		exit(1);
	if (pipe(pipefd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		child(av, pipefd, env);
	parent(av, pipefd, env);
}

void	child(char **av, int *pipefd, char **env)
{
	int	fd;

	fd = ft_open(av[1], 0);
	dup2(fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	my_executor(av[2], env);
}

void	parent(char **av, int *pipefd, char **env)
{
	int	fd;

	fd = ft_open(av[4], 1);
	dup2(fd, 1);
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	my_executor(av[3], env);
}

void	my_executor(char *command, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(command, ' ');
	path = path_finder(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		my_freer(s_cmd);
		exit(127);
	}
}

char	*path_finder(char *command, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(my_getenv("PATH", env), ':');
	s_cmd = ft_split(command, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			my_freer(s_cmd);
			return (exec);
		}
		free(exec);
	}
	my_freer(allpath);
	my_freer(s_cmd);
	return (command);
}
