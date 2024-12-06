/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:21:50 by ajacinto          #+#    #+#             */
/*   Updated: 2024/11/11 22:21:52 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_helper(int	i, char **arg)
{
	char	*to_print;
	while (arg[i])
	{
		to_print = verifying_env_variables(arg[i]);
		printf("%s", to_print);
		i++;
		if (arg[i] != NULL)
			printf(" ");
	}
}

void	echo(char **arg)
{
	if (ft_strcmp(arg[1], "-n") == 0)
	{
		echo_helper(2, arg);
		printf("%%\n");
	}
	else
	{
		echo_helper(1, arg);
		printf("\n");
	}
}
