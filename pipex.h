/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:51:24 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/03 11:08:29 by tberube-         ###   ########.fr       */
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
	char **env_path;
	int	find_path;
	char **env_split;
	char *cmd_path[2];
	int fds[2];
	char	*cmdjoin;
	char	*full_path;
	
}	t_struct ;

int		main(int argc, char **argv, char **envp);
void	parsing(int argc, char **argv, char **envp, t_struct *data);
void	nb_argument(int argc);
void	create_fd(char **argv, t_struct *data);
void	check_cmd(char **argv, t_struct *data);
void	split_path(t_struct *data, char **envp);
void	quit_cmd(t_struct *data);

#endif