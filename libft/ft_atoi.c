/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:15:33 by tberube-          #+#    #+#             */
/*   Updated: 2021/10/18 14:21:06 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	aff;
	unsigned int	plus;
	unsigned int	stop;

	aff = 0;
	plus = 1;
	stop = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			plus = -1;
		stop++;
		str++;
	}
	if (stop > 1)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		aff = aff * 10 + (*str - '0');
		str++;
	}
	return (aff * plus);
}
