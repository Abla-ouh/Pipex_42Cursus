/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 23:03:59 by abouhaga          #+#    #+#             */
/*   Updated: 2022/04/10 02:29:31 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
}

void	error_handler(void)
{
	perror("pipex");
	exit(1);
}

static void	fail_execve(char **arg)
{
	write(2, "pipex: ", 8);
	write(2, "command not found: ", 20);
	write(2, arg[0], ft_strlen(arg[0]));
	write(2, "\n", 1);
	exit(127);
}

void	first_cmd(char **env, char *infile, char **arg, int *pipe_fd)
{
	int		fd;
	char	*cmd_path;

	fd = open(infile, O_RDONLY);
	if (!ft_strchr(arg[0], '/'))
		cmd_path = find_path(arg[0], env);
	else
		cmd_path = arg[0];
	if (fd == -1)
		error_handler();
	if (dup2(pipe_fd[1], 1) == -1)
		error_handler();
	if (dup2(fd, 0) == -1)
		error_handler();
	close(fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (execve(cmd_path, arg, env) == -1)
		fail_execve(arg);
}

void	second_cmd(char **env, char *outfile, char **arg, int *pipe_fd)
{
	int		fd;
	char	*cmd_path;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!ft_strchr(arg[0], '/'))
		cmd_path = find_path(arg[0], env);
	else
		cmd_path = arg[0];
	if (fd == -1)
		error_handler();
	if (dup2(pipe_fd[0], 0) == -1)
		error_handler();
	if (dup2(fd, 1) == -1)
		error_handler();
	close(fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (execve(cmd_path, arg, env) == -1)
		fail_execve(arg);
}
