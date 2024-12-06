/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:22:47 by ajacinto          #+#    #+#             */
/*   Updated: 2024/05/17 22:22:49 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*str;

	str = 0;
	begin = 0;
	end = ft_strlen(s1);
	if (s1 && set)
	{
		while (s1[begin] && ft_strchr(set, s1[begin]))
			begin++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > begin)
			end--;
		str = (char *)malloc(sizeof(char) * (end - begin + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s1 + begin, (end - begin + 1));
	}
	return (str);
}
