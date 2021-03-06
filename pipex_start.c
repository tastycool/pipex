/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:17:02 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/20 12:15:08 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(char **argv, char **envp, t_struct *data)
{
	if (pipe(data->pipefd) < 0)
		return ;
	if (data->fds[0] != -1)
	{
		data->child = fork();
		if (data->child == 0)
		{
			dup2(data->fds[0], STDIN_FILENO);
			close(data->fds[0]);
			dup2(data->pipefd[1], STDOUT_FILENO);
			close(data->pipefd[1]);
			close(data->pipefd[0]);
			execve(data->cmd_path[0], ft_split(argv[2], ' '), envp);
			quit_fork(data);
		}	
	}
	close(data->fds[0]);
	dup2(data->pipefd[0], STDIN_FILENO);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	dup2(data->fds[1], STDOUT_FILENO);
	close(data->fds[1]);
}

void	pipex_end(char **argv, char **envp, t_struct *data)
{
	if (data->fds[1] != -1)
	{
		data->child = fork();
		if (data->child == 0)
		{
			execve(data->cmd_path[1], ft_split(argv[3], ' '), envp);
			free(data->cmd_path[1]);
			quit_fork(data);
		}
	}
	close(data->fds[1]);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
}

void	open_fd(char **argv, t_struct *data)
{
	data->fds[0] = open(argv[1], O_RDONLY, 0666);
	data->fds[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->fds[1] < 0)
	{
		dprintf(2, "%s: %s\n", strerror(errno), argv[4]);
		quit_cmd(data, 1);
	}
}
