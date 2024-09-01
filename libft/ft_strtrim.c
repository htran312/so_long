/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:45:26 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/14 20:03:42 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if ((!s1) || (!set) || (!*s1))
		return (ft_strdup(""));
	j = 0;
	while ((s1[j]) && (ft_strchr(set, s1[j])))
		j++;
	i = ft_strlen(s1);
	while ((0 < i -1) && (ft_strrchr(set, s1[i -1])))
		i--;
	return ((char *)(ft_substr(s1, j, i - j)));
}
