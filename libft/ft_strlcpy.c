/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:19:29 by tberube-          #+#    #+#             */
/*   Updated: 2021/10/07 14:01:07 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*a_dst;
	const char	*a_src;
	size_t		j;

	a_dst = dst;
	a_src = src;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dstsize > 1 && a_src[j] != '\0')
	{
		a_dst[j] = a_src[j];
		j++;
		dstsize--;
	}
	a_dst[j] = '\0';
	while (a_src[j] != '\0')
		j++;
	return (j);
}
