/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:17:02 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/15 15:31:06 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(char **argv, char **envp, t_struct *data)
{
	if (pipe(data->pipefd) < 0)
	{
	//	printf("pipefd");
		return ;	
	}
	if (data->fds[0] != -1)
	{
	//	printf("a l'exterieur du 1er child : \n");
		data->child = fork();
		if (data->child == 0)
		{
			//printf("a l'inteieur du 1er child : \n");
			dup2(data->fds[0], 0);
			close(data->fds[0]);
			dup2(data->pipefd[1], 1);
			close(data->pipefd[1]);
			close(data->pipefd[0]);
			execve(data->cmd_path[0], ft_split(argv[2], ' '), envp);
			free(data->cmd_path[0]);
			exit(1);
	//		printf("child exit");
		}	
	//	dprintf(2, "else child 1\n");
		//close(data->fds[0]);
		dup2(data->pipefd[0], 0);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		dup2(data->fds[1], 1);
		close(data->fds[1]);
		//wait(&data->child);
	}
}

void	pipex_end(char **argv, char **envp, t_struct *data)
{
	//dprintf(2, "criss\n");
	if (data->fds[1] != -1)
	{
		data->child = fork();
		//dprintf(2, "a l'exterieur du 2e child : %d\n", data->child);
		if (data->child == 0)
		{
			//printf("a l'interieur du 2e child : %d\n", data->child);
			//close(data->fds[1]);
			execve(data->cmd_path[1], ft_split(argv[3], ' '), envp);
			dprintf(2, "child 2 error");
			free(data->cmd_path[1]);
			exit(1);
		}
	}
	//close(data->fds[1]);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
}

void	open_fd(char **argv, t_struct *data)
{
	data->fds[0] = open(argv[1], O_RDONLY);
	data->fds[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->fds[1] < 0)
		quit_cmd(data);
}