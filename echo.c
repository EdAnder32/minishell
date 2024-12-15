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
	int i;
	int no_newline;

	i = 1;
	no_newline = 0;
	while (arg[i] && strncmp(arg[i], "-n", 2) == 0)
	{
		int j = 1;
		while (arg[i][j] == 'n')
			j++;
		if (arg[i][j] != '\0')
			break;
		no_newline = 1;
		i++;
	}
	echo_helper(i, arg);
	if (!no_newline)
		printf("\n");
}
