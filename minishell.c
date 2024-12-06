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

void	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

void	ft_pwd(void)
{
	char	path[4096];

	getcwd(path, 4096);
	printf("%s\n", path);
}

void	ft_exit()
{
	exit(0);
}

void	take_var_from_command(char *command, char *var)
{
	int	i;

	i = 0;
	while (command[i] && command[i] != '=')
	{
		var[i] = command[i];
		i++;
	}
	var[i] = '\0';
}

int		find_equal_words(char *var, char *command)
{
	int	i;

	i = 0;
	while (var[i] && command[i] && var[i] == command[i])
		i++;
	if (var[i] == '\0' && command[i] == '\0')
		return (1);
	return (0);
}

int		see_if_command_exists(char *envp, char *command)
{
	int	i;
	char	var[1024];

	i = 0;
	take_var_from_command(envp, var);
	if (find_equal_words(var, command))
		return (1);
	ft_memset(var, '\0', 1024);
	i++;
	return (0);
}

int		is_actually_a_command(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == '=')
		{
			if (i == 0)
			{
				printf("export: `=': not a valid identifier\n");
				return (0);
			}
			else if (i == 1 && command[i + 1] == '\0')
				return (1);
			return (1);
		}
		i++;
	}
	return (0);
}

void	order_matrix_bubble_sort(char **matrix, int size)
{
	char	*tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (ft_strcmp(matrix[j], matrix[j + 1]) > 0)
			{
				tmp = matrix[j];
				matrix[j] = matrix[j + 1];
				matrix[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

char	*create_env_var(char **atual_command)
{
	char	*str;

	if (atual_command[1] == NULL)
		str = ft_strjoin(atual_command[0], "");
	else
		str = ft_strjoin(atual_command[0], atual_command[1]);
	return (str);
}

char	**construct_env_matrix(char **matrix)
{
	char	**new_matrix;
	int			i;
	int			j;

	i = 0;
	while (matrix[i])
		i++;
	new_matrix = (char **)malloc(sizeof(char *) * (i + 1));
	new_matrix[i] = NULL;
	i = -1;
	while (matrix[++i])
	{
		j = 0;
		while (matrix[i][j])
			j++;
		new_matrix[i] = (char *)malloc(sizeof(char) * (j + 1));
		new_matrix[i][j] = '\0';
	}
	i = -1;
	while (matrix[++i])
	{
		j = -1;
		while (matrix[i][++j])
			new_matrix[i][j] = matrix[i][j];
	}
	return (new_matrix);
}

/*char	*var_without_double_quotes(char *var)
{
	char	*no_quotes_var;
	int		i;

	i = 0;
	while(var[i])
	{
		i++;
	}
	return (no_quotes_var);
}*/

void	export(char **command, char **env, char **envp)
{
	int	i;
	int	line_for_the_command;
	int	size;
	int	k;
	char	**atual_command;
	char	*str_no_quote;

	i = 0;
	size = 0;
	k = 1;
	line_for_the_command = -1;
	if (command[1] != NULL)
	{
		while (command[k])
		{
			atual_command = ft_split(command[k], '=');
			while (env[i])
			{
				if ((see_if_command_exists(env[i], atual_command[0]) == 1))
					line_for_the_command = i;
				i++;
			}
			if (line_for_the_command >= 0)
			{
				if (!is_actually_a_command(command[k]))
				{
					free_matrix(atual_command);
					return ;
				}
				env[line_for_the_command] = create_env_var(atual_command);
				envp[line_for_the_command] = env[line_for_the_command];
			}
			else
			{
				env[i] = create_env_var(atual_command);
				envp[i] = create_env_var(atual_command);
				i++;
				env[i] = NULL;
				envp[i] = NULL;
			}
			k++;
			free_matrix(atual_command);
		}
	}
	else
	{
		while (env[size])
			size++;
		order_matrix_bubble_sort(env, size);
		while (env[i] != NULL)
		{
			atual_command = ft_split(env[i], '=');
			str_no_quote = ft_strdup_no_quote(atual_command[1]);
			if (atual_command[1] == NULL && atual_command[0] != NULL)
				printf("declare -x %s=\"\"\n", atual_command[0]);
			else if (atual_command[0] != NULL)
				printf("declare -x %s=\"%s\"\n", atual_command[0], str_no_quote);
			free(str_no_quote);
			free_matrix(atual_command);
			i++;
		}
	}
	
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
	else
		return (printf("BashBrothers: command not found: '%s'\n", command));
	return (0);
}

void	process_command(t_tokens **token_list, char **envp)
{
	t_tokens	*tmp;
	int			i = 1;

	tmp = *token_list;
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
		//print_list(token_list);
		add_history(history);
		free_list(&token_list);
	}
}
