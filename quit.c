/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:36:47 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/03 11:14:13 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	quit_cmd(t_struct *data)
{
	int	i;

	i = 0;
	free(data->cmdjoin);
	free(data->full_path);
	i = 0;
	while (data->env_path[i] != NULL)
	{
		free(data->env_path[i]);
		i++;
	}
	free(data->env_path[i]);
	if (data->cmd_path[0] != NULL)
		free(data->cmd_path[0]);
	if (data->cmd_path[1] != NULL)
		free(data->cmd_path[1]);
}