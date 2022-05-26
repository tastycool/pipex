/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:19:39 by tberube-          #+#    #+#             */
/*   Updated: 2021/10/19 09:07:37 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *) haystack);
	while ((n != i + j) && haystack[i] != '\0')
	{
		while (haystack[i + j] != needle[j] && n != (i + j) && haystack[i])
		{
			j = 0;
			i++;
		}
		if (haystack[i + j] == needle[j] && n != i + j)
			j++;
		if (needle[j] == '\0')
			return ((char *) &haystack[i]);
	}
	return (0);
}
