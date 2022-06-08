/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:17:02 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/08 10:43:37 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(int argc, char **argv, char **envp, t_struct *data)
{
	(void)argc;
	data->pipe = pipe(data->pipefd);
	if (data->fds[0] != -1)
	{
		data->child = fork();
		if (data->child == 0) //dans le child
		{
			dup2(data->fds[0], 0); // remplace l'entrée standard par ton fichier
			close(data->fds[0]);
			dup2(data->pipefd[1], 1); // remplace la sortie standard par la sortie de ton pipe
			close(data->pipefd[1]);
			if(execve(data->cmd_path[0], ft_split(argv[2], ' '), envp) == -1);
				free(data->cmd_path[0]); 
			exit(1);
		}
		else
			perror("Fork: ");
	}
	else
		perror("Fork: ");
}
// void	pipex_end(int argc, char **argv, char **envp, t_struct *data)
// {
//
// 	data->child = fork();
// 	if (data->child = 0) //dans le child
// 	{
// 		dup2(data->fd_IN DE LA DERNIERE FOONCYTION, 0); // remplace l'entrée standard par ton fichier
// 		//close()
// 		dup2(data->TA SORTIE, 1); // remplace la sortie standard par la sortie de ton pipe
// 		// close
		//EXECUTE TA MARDE
		//QUIT SI ERREUR
		
// 	}
// 	return (pipe[0])
// }
void	open_fd(char **argv, t_struct *data)
{
	data->fds[0] = open(argv[1], O_RDONLY);
	data->fds[1] = open(argv[4], O_RDWR, 0644);
	if (data->fds[0] < 0 || data->fds[1] < 0)
		quit_cmd(data);
}