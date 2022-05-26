/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:38:11 by tberube-          #+#    #+#             */
/*   Updated: 2021/10/28 08:26:53 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;

	str = (char *)s1;
	len = ft_strlen(s1) + 1;
	str = malloc(len * sizeof(char));
	if (str == NULL)
		return (0);
	ft_memcpy(str, s1, len);
	return (str);
}
