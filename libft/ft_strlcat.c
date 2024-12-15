/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:58:35 by edalexan          #+#    #+#             */
/*   Updated: 2024/05/19 14:18:13 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lenght_s;
	size_t	lenght_d;

	i = 0;
	lenght_s = ft_strlen(src);
	lenght_d = ft_strlen(dst);
	if (size <= lenght_d)
		return (size + lenght_s);
	while (src[i] != '\0' && (lenght_d + i) < (size - 1))
	{
		dst[lenght_d + i] = src[i];
		i++;
	}
	dst[lenght_d + i] = '\0';
	return (lenght_d + lenght_s);
}
