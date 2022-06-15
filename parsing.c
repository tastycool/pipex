/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:01:31 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/15 15:07:07 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_cmd(t_struct *data)
{
	if (ft_strchr(data->full_path, ' '))
		data->find_cmd = ft_substr(data->full_path, 0, (ft_strlen(data->full_path)\
		- ft_strlen(ft_strchr(data->full_path, ' '))));
	else
		data->find_cmd = data->full_path;
}

void	parsing(int argc, char **argv, char **envp, t_struct *data)
{
	data->find_path = 0;
	while (ft_strncmp(envp[data->find_path], "PATH=", 5) != 0)
		data->find_path++;
	split_path(data, envp);
	nb_argument(argc);
	create_fd(argv, data);
	check_cmd(argv, data);
	data->cmds[0] = argv[2];
	data->cmds[1] = argv[3];
	close_fd(data);
}

void	nb_argument(int argc)
{
	if (argc != 5)
	{
		dprintf(2, "Error");
		exit(1);
	}
}

void	create_fd(char **argv, t_struct *data)
{	
	
	data->fds[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	data->fds[0] = open(argv[1], O_RDWR);
	if (data->fds[0] == -1)
		dprintf(2, "%s : %s\n", argv[1], strerror(errno));
}

void	check_cmd(char **argv, t_struct *data)
{
	int		i;
	int		j;
	
	j = 0;
	while (j < 2)
	{
		i = 0;
		data->cmdjoin = ft_strjoin("/", argv[j + 2]);
		while (data->env_path[i] != NULL)
		{
			data->full_path = ft_strjoin(data->env_path[i], data->cmdjoin);
			find_cmd(data);
			if (access(data->find_cmd, X_OK) == 0)
			{
				data->cmd_path[j] = data->find_cmd;
				break ;
			}
			free(data->full_path);
			i++;
		}
		free(data->cmdjoin);
		if (data->cmd_path[j] == NULL)
				quit_cmd(data);
		j++;	
	}	
}
