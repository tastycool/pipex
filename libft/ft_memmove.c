/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:19:14 by tberube-          #+#    #+#             */
/*   Updated: 2021/10/18 14:50:02 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*str1;
	const char	*str2;

	i = 0;
	str1 = dst;
	str2 = src;
	if (!str1 && !str2)
		return (0);
	if (str1 > str2)
	{
		while (len--)
			*(str1 + len) = *(str2 + len);
		return (str1);
	}
	while (len > i)
	{
		str1[i] = str2[i];
		i++;
	}
	return (str1);
}
