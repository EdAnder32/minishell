/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:09:38 by ajacinto          #+#    #+#             */
/*   Updated: 2024/10/23 14:26:26 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	pwd(void)
{
	char	path[4096];

	getcwd(path, 4096);
	printf("%s\n", path);
}

void	cd(char *command)
{
	/*PODE APAGAR TUDO QUE ESTIVER ABAIXO AJACINTO */
	(void)command;
	printf("Yea, oky\n");
}

int		find_var_in_env(char *env, char *command)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i + j] && env[i + j] == command[j])
		{
			j++;
			if (command[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int		see_if_command_exists(char **envp, char *command)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (find_var_in_env(envp[i], command))
		{
			//printf("Achou\n");
			return (1);
		}
		i++;
	}
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
			{
				// printf("Error: dumb error\n");
				return (1);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

char	*create_env_var(char **atual_command)
{
	char	*str;

	str = ft_strjoin(atual_command[0], atual_command[1]);
	return (str);
}

void	export(char **command, char **envp)
{
	//(void)command;
	//(void)envp;
	//printf("Yh\n");
	int	i;
	int	line_for_the_command;
	char	**atual_command;

	i = 0;
	line_for_the_command = 0;
	if (command[1] != NULL)
	{
		if (!is_actually_a_command(command[1]))
			return ;
		atual_command = ft_split(command[1], '=');
		if (command[2] == NULL)
		{
			command[2] = " ";
			command[3] = NULL;
		}
		while (envp[i])
		{
			if (see_if_command_exists(envp, atual_command[0]))
				line_for_the_command = i;
			i++;
		}
		if (line_for_the_command)
			envp[line_for_the_command] = create_env_var(atual_command);
		else
		{
			envp[i] = create_env_var(atual_command);
			envp[++i] = NULL;
		}
		free_matrix(atual_command);
	}
	else
	{
		while (envp[i] != NULL)
		{
			printf("declare -x %s\n", envp[i]);
			i++;
		}
	}
}

void	env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

void	process_command(char **command, char **envp)
{
	if (!ft_strcmp(command[0], "pwd"))
		pwd();
	else if (!ft_strcmp(command[0], "cd"))
		cd(command[0]);
	else if (!ft_strcmp(command[0], "exit"))
	{
		free_matrix(command);
		exit(0);
	}
	else if (!ft_strcmp(command[0], "export"))
		export(command, envp);
	else if (!ft_strcmp(command[0], "env"))
		env(envp);
	else
		printf("'%s': not a valid command\n", command[0]);
}

int	main(int ac, char **av, char **envp)
{
	char	**command;
	char	*history;

	(void)ac;
	(void)av;
	while (1)
	{
		history = readline("\e[32mbash >> \e[0m");
		command = ft_split(history, ' ');
		if (command[0])
		{
			process_command(command, envp);
			free_matrix(command);
			add_history(history);
		}
	}
}
