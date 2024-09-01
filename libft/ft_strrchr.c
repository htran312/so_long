/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:01:29 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/14 20:02:58 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		slen;
	char	ch;

	ch = c;
	slen = ft_strlen(str);
	if (str[slen] == ch)
		return ((char *) &str[slen]);
	while (slen >= 0)
	{
		if (str[slen] == ch)
			return ((char *) &str[slen]);
		slen--;
	}
	return (NULL);
}
