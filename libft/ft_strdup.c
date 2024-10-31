/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:52:19 by edalexan          #+#    #+#             */
/*   Updated: 2024/05/15 17:16:24 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	size;
	char	*new_str;
	char	*old_str;

	i = 0;
	old_str = (char *)s;
	size = ft_strlen(old_str);
	new_str = (char *)malloc(size + 1);
	if (new_str == NULL)
		return (NULL);
	while (old_str[i] != '\0')
	{
		new_str[i] = old_str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
