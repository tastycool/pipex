/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:56:23 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/16 14:58:04 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_struct	data;

	parsing(argc, argv, envp, &data);
	pipex_start(argv, envp, &data);
	pipex_end(argv, envp, &data);
	quit_cmd(&data, EXIT_SUCCESS);
}
