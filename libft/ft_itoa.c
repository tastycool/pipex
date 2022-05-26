/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:31:52 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/25 10:15:26 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	len_int(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*copy_return(char *ret, int n, int len)
{
	int	negative;

	negative = 0;
	if (n < 0)
	{
		negative++;
		n = n * -1;
	}
	while (len > 0)
	{
		len--;
		ret[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (negative > 0)
		ret[0] = '-';
	return (ret);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = len_int(n);
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (0);
	ret = copy_return(ret, n, len);
	return (ret);
}
