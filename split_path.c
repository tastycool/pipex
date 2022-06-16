/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:24:45 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/16 15:03:10 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	split_path(t_struct *data, char **envp)
{
	char	*tmp;

	data->env_path = ft_split(envp[data->find_path], ':');
	tmp = ft_strdup(data->env_path[0]);
	free(data->env_path[0]);
	data->env_path[0] = ft_substr(tmp, 5, ft_strlen(tmp));
	free(tmp);
}
