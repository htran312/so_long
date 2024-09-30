/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:12:05 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/30 20:25:42 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr_gnl(const char *str, int c)
{
	int		i;
	char	ch;

	ch = c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == ch)
		return ((char *) &str[i]);
	else
		return (NULL);
}

void	*ft_memcpy_gnl(void *to, const void *from, size_t n)
{
	size_t		i;
	char		*destination;
	const char	*source;

	destination = (char *)to;
	source = (const char *)from;
	if (!to && !source)
		return (NULL);
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (to);
}

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup_gnl(char *s1)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	len = ft_strlen_gnl(s1);
	ptr = (char *) malloc ((len +1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (ft_strdup_gnl(""));
	if (!s1)
		return (ft_strdup_gnl(s2));
	else if (!s2)
		return (ft_strdup_gnl(s1));
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	res = malloc ((s1_len + s2_len +1) * (sizeof(char)));
	if (!res)
		return (NULL);
	ft_memcpy_gnl(res, s1, s1_len);
	ft_memcpy_gnl((res + s1_len), s2, s2_len);
	res[s1_len + s2_len] = '\0';
	free(s1);
	return (res);
}
