/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:09:13 by edalexan          #+#    #+#             */
/*   Updated: 2024/12/03 11:09:29 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_strings(char **matrix)
{
    int i;

    i = 0;
    if (!matrix)
        return ;
    while (matrix[i])
        free(matrix[i++]);
    free(matrix);
}

char    *build_path_for_command(char *command)
{
    char    *path;
    char    **new_path;
    char    *full_path;
    int         i;

    i = -1;
    path = getenv("PATH");
    if (!path)
        return (NULL);
    new_path = ft_split(path, ':');
    while (new_path[++i])
    {
        full_path = malloc(ft_strlen(new_path[i])  + ft_strlen(command) + 2);
        ft_strcpy(full_path, new_path[i]);
        ft_strcat(full_path, "/");
        ft_strcat(full_path, command);
        if (access(full_path, X_OK) == 0)
        {
            free_strings(new_path);
            return (full_path);
        }
        free(full_path);
    }
    free_strings(new_path);
    return (NULL);
}

void    pipes(void)
{
    int pid1;
    int pid2;
    int pipes[2];

    pipe(pipes);
    pid1 = fork();
    if (pid1 == 0)
    {
        close(pipes[0]);
        dup2(pipes[1], STDOUT_FILENO);
        close(pipes[1]);
        char *command[] = {"/bin/ls", NULL};
        execve(command[0], command, NULL);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    pid2 = fork();
    if (pid2 == 0)
    {
        close(pipes[1]);
        dup2(pipes[0], STDIN_FILENO);
        close(pipes[0]);
        char *command[] = {"/usr/bin/wc", NULL};
        execve(command[0], command, NULL);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    close(pipes[0]);
    close(pipes[1]);
    wait(NULL);
    wait(NULL);
}
