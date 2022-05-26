/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:01:43 by tberube-          #+#    #+#             */
/*   Updated: 2021/10/28 12:03:50 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	if (!s || !f)
		return (0);
	str = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!str)
		return (0);
	while (*s)
	{
		str[i] = (*f)(i,*s++);
		i++;
	}
	return (str);
}
