/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:19:00 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/25 10:15:07 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*o_s;
	unsigned char	o_c;

	o_s = (unsigned char *)s;
	o_c = (unsigned char)c;
	while (n--)
	{
		if (*o_s == o_c)
			return (o_s);
		o_s++;
	}
	return (0);
}
