/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:12:52 by tberube-          #+#    #+#             */
/*   Updated: 2021/10/25 12:42:18 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		j;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[i] && ft_strrchr(set, s1[i]))
		i++;
	while (j > i && ft_strrchr(set, s1[j - 1]))
		j--;
	return (ft_substr(s1, i, (j - i)));
}
