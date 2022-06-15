/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:36:47 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/15 13:05:44 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	quit_fork(t_struct *data, char *str)
{
	dprintf(2, "%s\n", str);
	quit_cmd(data);
}

void	quit_cmd(t_struct *data)
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
}

void	close_fd(t_struct *data)
{
	if (data->fds[0] >= 0)
		close(data->fds[0]);
	if (data->fds[1] >= 0)
		close(data->fds[1]);
}