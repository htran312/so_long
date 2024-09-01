/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:23:15 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/16 16:28:00 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long	res;
	long long	check;
	int			sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		check = res * 10 + *str - '0';
		if (check / 10 != res && sign == -1)
			return (0);
		if (check / 10 != res && sign == 1)
			return (-1);
		res = check;
		str++;
	}
	return (sign * res);
}
