/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:51:23 by ajacinto          #+#    #+#             */
/*   Updated: 2024/05/16 18:51:25 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	lenght_s;
	size_t	lenght_d;

	i = 0;
	lenght_s = ft_strlen(src);
	lenght_d = ft_strlen(dst);
	while (src[i] != '\0')
	{
		dst[lenght_d + i] = src[i];
		i++;
	}
	dst[lenght_d + i] = '\0';
	return (lenght_d + lenght_s);
}
