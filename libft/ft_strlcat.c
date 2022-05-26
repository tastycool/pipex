/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:45:01 by tberube-          #+#    #+#             */
/*   Updated: 2021/10/18 15:57:29 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;
	size_t	j;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	i = 0;
	j = len_d;
	if (dstsize <= len_d)
		return (len_s + dstsize);
	while (dstsize - 1 > len_d && src[i])
	{
		dst[j] = src[i];
		j++;
		i++;
		dstsize--;
	}
	dst[j] = '\0';
	return (len_s + len_d);
}
