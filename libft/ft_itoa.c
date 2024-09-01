/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:35:49 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/14 17:44:24 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = (-1) * n;
	}
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		nlen;
	int		i;

	nlen = get_len(n);
	num = n;
	res = malloc((nlen + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = nlen -1;
	while (i >= 0)
	{
		if (num < 0)
			num = (-1) * num;
		res[i] = (num % 10) + 48;
		num = num / 10;
		i--;
	}
	res[nlen] = 0;
	if (n < 0)
		res[0] = '-';
	return (res);
}
