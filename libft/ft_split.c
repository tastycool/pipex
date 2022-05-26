/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:25:10 by tberube-          #+#    #+#             */
/*   Updated: 2022/05/05 10:36:03 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>

static int	word_count(const char *s, char c)
{
	size_t		i;
	int			w_count;

	i = 0;
	w_count = 0;
	while (i < ft_strlen(s))
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
		{
			w_count++;
		}
		i++;
	}
	return (w_count);
}

static void	copy(char *s, int c, char **ret)
{
	int	tab;
	int	start;
	int	len;
	int	w_len;

	tab = 0;
	start = 0;
	len = 0;
	while (s[len])
	{
		w_len = 0;
		if (s[len] != c)
			start = len;
		while (s[len] != c && s[len])
		{
			w_len++;
			len++;
		}
		while (s[len] == c && s[len] != '\0')
			len++;
		ret[tab] = ft_substr(s, start, w_len);
		tab++;
	}
}

char	**ft_split(char	const *s, char c)
{
	char	**ret;
	char	*trim_tmp;
	char	delim[2];

	if (!s)
		return (0);
	delim[0] = c;
	delim[1] = '\0';
	trim_tmp = ft_strtrim(s, delim);
	if (!trim_tmp)
		return (0);
	ret = (char **)ft_calloc((word_count(trim_tmp, c) + 1), sizeof(char *));
	if (!ret)
		return (NULL);
	copy(trim_tmp, c, ret);
	free(trim_tmp);
	return (ret);
}
