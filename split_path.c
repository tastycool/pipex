/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:24:45 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/03 09:56:53 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	split_path(t_struct *data, char **envp)
{
	data->env_path = ft_split(envp[data->find_path], ':');
	data->env_path[0] = ft_substr(data->env_path[0], 5, ft_strlen(data->env_path[0]));
}