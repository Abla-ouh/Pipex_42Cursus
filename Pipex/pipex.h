/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:35:57 by abouhaga          #+#    #+#             */
/*   Updated: 2022/04/15 02:06:40 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

/************************----Mandatory----***************************/

void	create_child(char **av, int i, int *pipe_fd, char **env);
void	second_cmd(char **env, char *outfile, char **arg, int *pipe_fd);
void	first_cmd(char **env, char *infile, char **arg, int *pipe_fd);
char	*find_path(char *cmd_name, char **env);
void	free_all(char **paths);
void	error_handler(void);

/*************************----UTILS----******************************/
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
int		ft_strncmp(char *str1, char *str2, size_t n);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

#endif
