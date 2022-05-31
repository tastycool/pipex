/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:01:31 by tberube-          #+#    #+#             */
/*   Updated: 2022/05/30 15:08:56 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing(int argc, char **argv, char **envp)
{
	nb_argument(argc);
	create_fd(argc, argv);
}

void	nb_argument(int argc)
{
	if (argc < 5 || argc > 5)
	{
		dprintf(2, "Error");
		exit(1);
	}
}

void	create_fd(int argc, char **argv)
{
	open(argv[4], O_RDWR | O_CREAT, 0777);
}
