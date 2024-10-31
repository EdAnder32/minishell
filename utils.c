/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:30:03 by edalexan          #+#    #+#             */
/*   Updated: 2024/10/23 14:22:22 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    // while (limit > 0)
    // {
    //     if (s1[i] == s2[i])
    //         i++;
    //     limit--;
    // }
    // if (s1[i] == '\0' && s2[i] == '\0')
    //     return (0);
    // else if (s1[i] == '\0')
    //     return (1);
    // else if (s2[i] == '\0')
    //     return (-1);
    return (s1[i] - s2[i]);
}

int     ft_find_last_occur(char *s1, char *s2)
{
    int i;
    int j;
    int start;

    j = 0;
    i = 0;
    start = 0;
    while (s1[i])
    {
        while (s1[i] == s2[j])
        {
            if (start == 0)
                start = i;
            i++;
            j++;
            if (s2[j] == '\0')
                return (i);
        }
        start = 0;
        j = 0;
        i++;
    }
    return (start);
}

char    *ft_strstr(char *s1, char *s2)
{
    char    *str;
    int     j;
    int     i;

    i = 0;
    j = ft_find_last_occur(s1, s2);
    printf("Last occur: %d\n", j);
    if (s1[j] == '\0')
        return (NULL);
    while (s1[j])
    {
        i++;
        j++;
    }
    str = (char *)malloc(sizeof(char) * i + 1);
    str[i] = '\0';
    i = 0;
    j = ft_find_last_occur(s1, s2);
    printf("Last occur: %d\n", j);
    while (s1[j])
    {
        str[i] = s1[j];
        printf("%c\n", s1[j]);
        i++;
        j++;
    }
    printf("EXPORTED: %s\n", str);
    return (str);
}

/*To remove: FT_SPLIT */
static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!s2)
			return (free_array(s2, word));
		ft_putword(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (0);
	s2 = ft_split_words(s, c, s2, num_words);
	return (s2);
}
/*TO REMOVE */

/*TO REMOVE: FT_STRJOIN*/
int     ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	in;
	char	*n_str;

	i = 0;
	in = 0;
	n_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!n_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		n_str[in] = s1[i];
		i++;
		in++;
	}
    n_str[in++] = '=';
	i = 0;
	while (s2[i] != '\0')
	{
		n_str[in] = s2[i];
		i++;
		in++;
	}
	n_str[in] = '\0';
	return (n_str);
}

char	*ft_strjoin_modified_for_export(char *s1, char *s2)
{
	size_t	i;
	size_t	in;
	char	*n_str;

	i = 0;
	in = 0;
	n_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 4);
	if (!n_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		n_str[in] = s1[i];
		i++;
		in++;
	}
     n_str[in++] = '=';
     n_str[in++] = '"';
	i = 0;
	while (s2[i] != '\0')
	{
		n_str[in] = s2[i];
		i++;
		in++;
	}
    n_str[in++] = '"';
	n_str[in++] = '\0';
    printf("string: %s\n", n_str);
	return (n_str);
}
/*TO REMOVE*/
