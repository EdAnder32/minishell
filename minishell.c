/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:09:38 by ajacinto          #+#    #+#             */
/*   Updated: 2024/12/03 12:04:09 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i][0] != ' ' && matrix[i][1] != '\0')
			free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_exit()
{
	exit(0);
}

int    find_command_in_path(char *command)
{
	char	**path;
	int			process;

	path = malloc(sizeof(char *) + 2);
	path[1] = NULL;
	path[0] = build_path_for_command(command);
	if (path[0] == NULL)
		return (0);
	if (path)
	{
		process = fork();
		if (process == 0)
		{
			execve(path[0], path, NULL);
			free(path[0]);
			exit(EXIT_FAILURE);
		}
	}
	wait(NULL);
	free(path[0]);
    return (1);
}

int		find_built_in(char *command, char **envp, t_tokens *token_list)
{
	// if (ft_strncmp(command, "echo", 4) == 0)
	// 	ft_echo(envp);
	if (ft_strncmp(command, "cd", 2) == 0)
		ft_cd(token_list);
	else if (ft_strncmp(command, "pwd", 3) == 0)
		ft_pwd();
	// if (ft_strncmp(command, "export", 6) == 0)
	// 	ft_exit();
	// if (ft_strncmp(command, "unset", 5) == 0)
	// 	ft_exit();
	else if (ft_strncmp(command, "env", 3) == 0)
		ft_env(envp);
	else if (ft_strncmp(command, "exit", 4) == 0)
		ft_exit();
	else if (!find_command_in_path(command))
		printf("BashBrothers: command not found: '%s'\n", command);
	return (0);
}

void	process_command(t_tokens **token_list, char **envp)
{
	t_tokens	*tmp;
	int			i = 1;

	tmp = *token_list;
	(void)envp;
	while (tmp)
	{
		if (tmp->type == 1)
			find_built_in(tmp->value, envp, *token_list);
		tmp = tmp->next;
		i++;
	}
}

void	free_list(t_tokens **token_list)
{
	t_tokens	*tmp;

	while ((*token_list) != NULL)
	{
		tmp = (*token_list)->next;
		free((*token_list)->value);
		free(*token_list);
		*token_list = tmp;
	}
}

int	main(int ac, char **av, char **envp)
{
	//char	**env;
	char		*history;
	t_tokens    *token_list;

	(void)ac;
	(void)av;
	//env = construct_env_matrix(envp);
	token_list = NULL;
	while (1)
	{
		history = readline("BashBrothers >> ");
		process_string_to_token(history, &token_list);
		process_command(&token_list, envp);
		add_history(history);
		free_list(&token_list);
	}
}
