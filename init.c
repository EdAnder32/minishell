/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:44:37 by edalexan          #+#    #+#             */
/*   Updated: 2024/10/15 15:27:10 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*to print*/
int	putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write (1, "(null)", 6));
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

/*main function*/
int	putnbr(int n)
{
	char	digit[10] = "0123456789";
	if (n > 10)
		putnbr(n / 10);
	return (write (1, &digit[n % 10], 1));
}

int	main(int ac, char **av)
{
	int	number;

	if (ac == 2)
	{
		number = putstr(av[1]);
		putstr("\nReturn:");
		putnbr(number);
	}
	return (0);
}
