/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr_uppercase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:46:29 by htran-th          #+#    #+#             */
/*   Updated: 2024/07/26 17:22:40 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned int	ft_putxnbr_uppercase(unsigned int n, unsigned int base)
{
	int		count;
	int		temp;
	char	*symbol;

	symbol = "0123456789ABCDEF";
	count = 0;
	temp = 0;
	if (n < base)
		temp += ft_putchar(symbol[n]);
	else
	{
		{
			temp += ft_putxnbr_uppercase((n / base), base);
			if (temp == -1)
				return (-1);
		}
		temp += ft_putchar(symbol[n % base]);
		if (temp == -1)
			return (-1);
	}
	return (temp + count);
}
