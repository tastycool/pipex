/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:19:11 by tberube-          #+#    #+#             */
/*   Updated: 2021/10/18 14:49:36 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	const char		*str2;

	i = 0;
	str1 = dst;
	str2 = src;
	if (!str1 && !str2)
		return (0);
	while (n > i)
	{
		str1[i] = str2[i];
		i++;
	}
	return (str1);
}
