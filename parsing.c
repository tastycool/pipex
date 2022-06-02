/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:01:31 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/02 15:29:58 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing(int argc, char **argv, char **envp, t_struct *data)
{
	data->find_path = 0;
	while(!ft_strnstr(envp[data->find_path], "PATH=/Sy", ft_strlen(envp[data->find_path])))
		data->find_path++;
	printf("%s", envp[data->find_path]);
	split_path(data, envp);
	nb_argument(argc);
	create_fd(argv);
	//check_cmd(argv)
}

void	nb_argument(int argc)
{
	if (argc < 5 || argc > 5)
	{
		dprintf(2, "Error");
		exit(1);
	}
}

void	create_fd(char **argv)
{	
	int fd1;
	int fd2;
	
	fd1 = open(argv[1], O_RDWR);
	if (fd1 == -1)
		dprintf(2, "%s : %s\n", argv[1], strerror(errno));
	fd2 = open(argv[4], O_RDWR | O_CREAT, 0666);
}

void	check_cmd(char **argv)
{
	access(argv[2], X_OK);
}
