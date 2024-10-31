/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:24:18 by edalexan          #+#    #+#             */
/*   Updated: 2024/05/17 16:54:01 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int		size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	ft_alloc(char **retorno, int n, int *size)
{
	*size = ft_size(n);
	if (n <= 0)
		(*size)++;
	*retorno = (char *)malloc(sizeof(char) * (*size + 1));
}

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	size_t	num;
	int		size;
	char	*retorno;

	ft_alloc(&retorno, n, &size);
	if (retorno == NULL)
		return (NULL);
	retorno[size] = '\0';
	if (n == 0)
		retorno[0] = '0';
	num = ft_abs(n);
	if (n < 0)
		retorno[0] = '-';
	while (num)
	{
		retorno[--size] = (num % 10) + '0';
		num /= 10;
	}
	return (retorno);
}
