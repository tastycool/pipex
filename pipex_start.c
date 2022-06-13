/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:17:02 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/10 10:25:54 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(char **argv, char **envp, t_struct *data)
{
	data->pipe = pipe(data->pipefd);
	if (data->fds[0] != -1)
	{
		data->child = fork();
		printf("data.child : %d\n", data->child);
		if (data->child == 0)
		{
			dup2(data->fds[0], 0);
			close(data->fds[0]);
			dup2(data->pipefd[1], 1);
			close(data->pipefd[1]);
			if (execve(data->cmd_path[0], ft_split(argv[2], ' '), envp) == -1)
				free(data->cmd_path[0]); 
			exit(1);
		}
		else
			quit_fork(data, "child 1 not found");
	}
}

void	pipex_end(char **argv, char **envp, t_struct *data)
{
	
	if (data->fds[1] != -1)
	{
		data->child = fork();
		//dprintf(2, "c lui quon veut : %d\n", data->child);
		if (data->child == 0)
		{
			//printf("data.child : %d\n", data->child);
			dup2(data->fds[1], 1);
			close(data->fds[1]);
			if (execve(data->cmd_path[1], ft_split(argv[3], ' '), envp) == -1)
				free(data->cmd_path[0]);
			exit(1);	
		}
		else
			quit_fork(data, "child 2 not found");
	}
	else
		quit_fork(data, "Error with outfile");
}

void	open_fd(char **argv, t_struct *data)
{
	data->fds[0] = open(argv[1], O_RDONLY);
	data->fds[1] = open(argv[4], O_RDWR, 0644);
	if (data->fds[1] < 0)
		quit_cmd(data);
}