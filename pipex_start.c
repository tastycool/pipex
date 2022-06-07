/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:17:02 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/07 14:49:54 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(int argc, char **argv, char **envp, t_struct *data)
{
	pipe(data->pipefd);
	data->child = fork();
	if (data->child = 0) //dans le child
	{
		dup2(data->fds[0], 0); // remplace l'entrée standard par ton fichier
		//close()
		dup2(data->pipefd[1], 1); // remplace la sortie standard par la sortie de ton pipe
		// close
		// EXECUTE TA MARDE
		// EXIT(1)
	}
	return (pipe[0]) //doit lire dans le end car le pipe vas continuer vers la 2e cmd
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