/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:41:48 by htran-th          #+#    #+#             */
/*   Updated: 2024/05/15 16:57:06 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_count(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
	}
	return (count);
}

static void	free_arr(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		ar[i] = NULL;
		i++;
	}
	free(ar);
	ar = NULL;
}

static int	get_word_length(char const *s, int start, char c)
{
	size_t	len;

	len = 0;
	while (s[start + len] && s[start + len] != c)
	{
		len++;
	}
	return (len);
}

static char	**word_fill(char const *s, char c, char **split, int array)
{
	int	i;
	int	start;

	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			start = i;
			split[array] = ft_substr(s, start, get_word_length(s, start, c));
			if (!split[array])
			{
				free_arr(split);
				return (NULL);
			}
			array++;
			i += get_word_length(s, start, c);
		}
	}
	split[array] = (NULL);
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		array;
	int		word;

	if (!s)
		return (NULL);
	array = 0;
	word = get_word_count(s, c);
	split = (char **)malloc((word + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = word_fill(s, c, split, array);
	return (split);
}
