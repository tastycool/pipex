/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:19:42 by tberube-          #+#    #+#             */
/*   Updated: 2021/10/18 13:37:12 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
retourne la premiere occurence dun caracter de set a linterieur de s1
*/
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	src;
	int				i;
	char			*dst;

	dst = (char *)s;
	src = c;
	i = 0;
	while (dst[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (dst[i] == src)
			return (&dst[i]);
		i--;
	}
	return (0);
}
