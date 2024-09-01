/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:56:31 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/14 18:02:57 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*memory;
	size_t			i;

	memory = (unsigned char *) str;
	i = 0;
	while (i < len)
	{
		memory[i] = c;
		i++;
	}
	return (str);
}
