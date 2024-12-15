/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:00:01 by ajacinto          #+#    #+#             */
/*   Updated: 2024/11/11 20:00:03 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*verifying_env_variables(char *command)
{
	char	*name_env_variables;

	if (command[0] == '$')
	{
		name_env_variables = command + 1;
		name_env_variables = getenv(name_env_variables);
		if (name_env_variables != NULL)
			return (name_env_variables);
	}
	return (command);
}

char *remove_quotes(char *str)
{
	if (!str || str[0] != '"' || str[strlen(str) - 1] != '"')
		return str;
	str[strlen(str) - 1] = '\0';
	return str + 1;
}

void	cd(char *command)
{
	if (command == NULL || ft_strcmp(command, " ") == 0
		|| ft_strcmp(command, "") == 0)
	{
		command = getenv("HOME");
		if (command == NULL)
			perror("HOME is not define");
	}
	else
	{
		command = verifying_env_variables(command);
		command = remove_quotes(command);
		if (chdir(command) == -1)
			printf("no such file or directory: %s\n", command);
	}
}

void	ft_cd(t_tokens *token_list)
{
	t_tokens	*tmp;
	int			position;

	position = 0;
	tmp = token_list;
	while (tmp)
	{
		position++;
		tmp = tmp->next;
	}
	if (position == 2)
		cd(token_list->next->value);
	else if (position > 2)
		printf("cd: to many arguments\n");
}
