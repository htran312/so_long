/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:38:46 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/14 17:58:30 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t n)
{
	char	*destination;
	char	*source;

	destination = (char *)to;
	source = (char *)from;
	if (to == NULL && from == NULL)
		return (NULL);
	if (destination <= source)
	{
		while (n--)
		{
			*destination++ = *source++;
		}
	}
	else if (source < destination)
	{
		destination += n - 1;
		source += n - 1;
		while (n--)
		{
			*destination-- = *source--;
		}
	}
	return (to);
}
