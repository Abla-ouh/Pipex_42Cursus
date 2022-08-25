/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:34:19 by abouhaga          #+#    #+#             */
/*   Updated: 2022/04/15 00:32:02 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*acces_command(char *cmd_name, char **paths)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd_name);
		if (access(cmd_path, X_OK) == 0)
			break ;
		i++;
	}
	return (cmd_path);
}

char	*find_path(char *cmd_name, char **env)
{
	int		i;
	char	**paths;
	char	*cmd_path;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	if (env[i] == NULL)
		error_handler();
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		cmd_path = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(cmd_path);
		i++;
	}
	cmd_path = acces_command(cmd_name, paths);
	free_all(paths);
	return (cmd_path);
}

void	create_child(char **av, int i, int *pipe_fd, char **env)
{
	pid_t	childpid;
	char	**arg;

	childpid = fork();
	if (childpid == -1)
		error_handler();
	if (childpid == 0)
	{
		arg = ft_split(av[i], ' ');
		if (arg == NULL)
			error_handler();
		if (i == 2)
			first_cmd(env, av[1], arg, pipe_fd);
		if (i == 3)
			second_cmd(env, av[4], arg, pipe_fd);
	}
}

int	main(int ac, char **av, char **env)
{
	int	pipe_fd[2];

	if (ac != 5)
	{
		write(2, "Error : Wrong number of arguments\n", 34);
		exit(1);
	}
	if (pipe(pipe_fd) == -1)
		error_handler();
	if (!av[2][0] || !av[3][0])
		write(2, "pipex: No command\n", 18);
	create_child(av, 2, pipe_fd, env);
	create_child(av, 3, pipe_fd, env);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}
