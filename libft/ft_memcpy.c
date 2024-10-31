/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:49:33 by edalexan          #+#    #+#             */
/*   Updated: 2024/05/19 13:05:54 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*destination;
	const char	*source;

	i = 0;
	destination = (char *)dest;
	source = (const char *)src;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}
