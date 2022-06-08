/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:51:24 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/08 10:33:56 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdbool.h>
# include <stdio.h>
# include "libft/libft.h"
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct s_struct
{
	char 	**env_path;
	int		find_path;
	char 	**env_split;
	char 	*cmd_path[2];
	char 	*cmds[2];
	int 	fds[2];
	char	*cmdjoin;
	char	*full_path;
	int		pipefd[2];
	char	*find_cmd;
	int		child;
	int		pipe;
	
}	t_struct ;

int		main(int argc, char **argv, char **envp);
void	parsing(int argc, char **argv, char **envp, t_struct *data);
void	nb_argument(int argc);
void	create_fd(char **argv, t_struct *data);
void	check_cmd(char **argv, t_struct *data);
void	split_path(t_struct *data, char **envp);
void	quit_cmd(t_struct *data);
void	close_fd(t_struct *data);
void	open_fd(char **argv, t_struct *data);
void	pipex_start(int argc, char **argv, char **envp, t_struct *data);

#endif