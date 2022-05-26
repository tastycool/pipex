/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:15:00 by tberube-          #+#    #+#             */
/*   Updated: 2022/05/24 14:59:10 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atolong(const char *str)
{
	long		retour;
	int			i;
	int			negatif;

	negatif = 1;
	i = 0;
	retour = 0;
	if (str[0] == '-')
	{
		negatif = -1;
		i++;
	}
	while (str[i])
	{
		retour = (str[i] - '0') + (retour * 10);
		i++;
	}
	return (retour * negatif);
}
