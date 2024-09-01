/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:40:22 by htran-th          #+#    #+#             */
/*   Updated: 2024/07/26 17:22:21 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr(int n)
{
	int	count;
	int	temp;

	count = 0;
	temp = 0;
	if (n < 0)
	{
		{
			if (ft_putchar('-') == -1)
				return (-1);
			temp++;
			n *= -1;
		}
		temp += ft_putunbr(n, 10);
		if (temp == -1)
			return (-1);
	}
	else
		temp += ft_putunbr(n, 10);
	if (temp == -1)
		return (-1);
	return (count + temp);
}
