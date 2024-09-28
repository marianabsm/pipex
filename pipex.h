/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:33:25 by marianamest       #+#    #+#             */
/*   Updated: 2024/09/21 16:43:49 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>

/* main */
int		main(int ac, char **av, char **env);

/* utils */
void	my_freer(char **arr);
int		ft_open(char *file_name, int flag);
char	*my_getenv(char *name, char **env); // change name

/* pipex */
void	child(char **av, int *pipefd, char **env);
void	parent(char **av, int *pipefd, char **env);
char	*path_finder(char *command, char **env);
void	my_executor(char *command, char **env);

#endif
