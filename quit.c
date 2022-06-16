/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:36:47 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/16 15:02:38 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_check(t_struct *data, int j, char **argv)
{
	if (j == 0)
		dprintf(2, "%s: %s\n", strerror(errno), argv[2]);
	if (j == 1)
	{
		dprintf(2, "%s: %s\n", strerror(errno), argv[3]);
		quit_cmd(data, 1);
	}
}

void	quit_fork(t_struct *data)
{
	quit_cmd(data, 1);
}

void	quit_cmd(t_struct *data, int exit_code)
{
	int	i;

	i = 0;
	while (data->env_path[i] != NULL)
	{
		free(data->env_path[i]);
		i++;
	}
	free(data->env_path);
	if (data->cmd_path[0] != NULL)
		free(data->cmd_path[0]);
	if (data->cmd_path[1] != NULL)
		free(data->cmd_path[1]);
	close_fd(data);
	exit(exit_code);
}

void	close_fd(t_struct *data)
{
	if (data->fds[0] >= 0)
		close(data->fds[0]);
	if (data->fds[1] >= 0)
		close(data->fds[1]);
}
