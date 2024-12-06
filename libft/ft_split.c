/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 05:45:05 by ajacinto          #+#    #+#             */
/*   Updated: 2024/05/18 05:45:08 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_count_word(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_free(char **strs, int i)
{
	while (i > 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_len;
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!strs || !s)
		return (ft_free(strs, 0));
	i = 0;
	while (*s)
	{
		word_len = 0;
		while (*s == c && *s)
			s++;
		word_len = ft_count_word_len(s, c);
		if (word_len)
		{
			strs[i] = ft_substr(s, 0, word_len);
			if (!strs[i])
				return (ft_free(strs, i));
			i++;
		}
		s += word_len;
	}
	strs[i] = 0;
	return (strs);
}
