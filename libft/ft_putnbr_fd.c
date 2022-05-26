/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:59:23 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/05 11:01:27 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

void	ft_putnbr_fd(size_t n, size_t base_len, char *base, int fd)
{
	char	c;

	if (n >= base_len)
		ft_putnbr_fd(n / base_len, base_len, base, fd);
	c = base[(n % base_len)];
	write(1, &c, 1);
}
