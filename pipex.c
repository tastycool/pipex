/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:56:23 by tberube-          #+#    #+#             */
/*   Updated: 2022/06/03 11:16:40 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_struct	data;
	parsing(argc, argv, envp, &data); 	// premier fd (argv1) existe access existe ou existe pas ou fopen return 
							 			// premiere cmd (argv2) existe ou pas, avec envp
						 				// deuxieme cmd (argv3) existe ou pas, avec envp
										// deuxieme fd (argv4) existe ou pas, si existe pas tu le creer
	pipex_start(argc, argv, envp, &data);
}
