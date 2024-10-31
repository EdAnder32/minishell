/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:39:14 by edalexan          #+#    #+#             */
/*   Updated: 2024/05/15 19:10:16 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	in;
	char	*n_str;

	i = 0;
	in = 0;
	n_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!n_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		n_str[in] = s1[i];
		i++;
		in++;
	}
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
