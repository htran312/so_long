/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:48:52 by htran-th          #+#    #+#             */
/*   Updated: 2024/08/27 18:54:06 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr(char *str)
{
	int	i;
	int	res;
	int	temp;

	res = 0;
	temp = 0;
	if (!str)
	{
		temp = ft_putstr("(null)");
		if (temp == -1)
			return (-1);
	}
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			temp += ft_putchar(str[i]);
			if (temp == -1)
				return (-1);
			i++;
		}
	}
	return (res + temp);
}
