/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:51:24 by tberube-          #+#    #+#             */
/*   Updated: 2022/05/30 15:12:07 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdbool.h>
# include <stdio.h>
# include "libft.h"
# include "limits.h"
# include <unistd.h>
# include <fcntl.h>

int		main(int argc, char **argv, char **envp);
void	parsing(int argc, char **argv, char **envp);
void	nb_argument(int argc);

#endif