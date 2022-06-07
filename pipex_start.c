/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:17:02 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/07 12:57:55 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(int argc, char **argv, char **envp, t_struct *data)
{
	pipe(data->pipefd);
	data->child = fork();
	if (data->child = 0)
	{
		dup2(data->fds[0], 0);
		dup2(data->pipefd[1], 1);
		
	}
}

// void	open_fd(char **argv, t_struct *data)
// {
// 	data->fds[0] = open(argv[1], O_RDONLY);
// 	data->fds[1] = open(argv[4], O_RDWR, 0644);
// 	if (data->fds[0] < 0 || data->fds[1] < 0)
// 		quit_cmd(data);
// }