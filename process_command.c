/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:49:23 by edalexan          #+#    #+#             */
/*   Updated: 2024/11/27 09:49:37 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// NOMENCLATURA
// 1. COMANDO
// 2. ARGUMENTO
// 3. OPERADOR >>, <<, >, <
// 4. OPERADOR |

int     is_operator(char c)
{
    if (c == '>' || c == '<')
        return (1);
    if (c == '|' )
        return (2);
    return (0);
}

int determine_type(char *token, t_tokens *prev)
{
    if (is_operator(token[0]) == 1)
        return (3);
    if (is_operator(token[0]) == 2)
        return (4);
    if (prev == NULL || prev->type == 4)
        return (1);
    return (2);
}

void    add_token_to_node(char *token, t_tokens ***token_list)
{
    t_tokens    *node;
    t_tokens    *tmp;

    node = malloc(sizeof(t_tokens));
    node->value = ft_strdup(token);
    if (**token_list == NULL)
        node->type = determine_type(token, NULL);
    else
    {
        tmp = **token_list;
        while (tmp->next)
            tmp = tmp->next;
        node->type = determine_type(token, tmp);
    }
    node->next = NULL;
    if (**token_list == NULL)
        **token_list = node;
    else
    {
        tmp = **token_list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = node;
    }
}

void    process_string_to_token(char *command, t_tokens **token_list)
{
    char        *current_token;
    int             i;
    int             start;
    int             double_quotes;
    int             simple_quotes;
    int             op_len;

    i = 0;
    double_quotes = 0;
    simple_quotes = 0;
    while (command[i])
    {
        while (command[i] == ' ')
            i++;
        if (command[i] == '\0')
            break ;
        if (is_operator(command[i]) && !double_quotes)
        {
            op_len = 1;
            if ((command[i] == '>' && command[i + 1] == '>')
                || (command[i] == '<' && command[i + 1] == '<'))
                op_len = 2;
            current_token = malloc(op_len + 1);
            ft_strlcpy(current_token, command + i, op_len + 1);
            add_token_to_node(current_token, &token_list);
            free(current_token);
            i += op_len;
        }
        else
        {
            start = i;
            while (command[i] && (command[i] != ' ' || double_quotes || simple_quotes))
            {
                if (command[i] == '"')
                    double_quotes = !double_quotes;
                else if (command[i] == '\'')
                    simple_quotes = !simple_quotes;
                else if (is_operator(command[i]) && (!double_quotes || !simple_quotes))
                    break;
                i++;
            }
            current_token = malloc(sizeof(char) * (i - start + 1));
            ft_strlcpy(current_token, command + start, i - start + 1);
            add_token_to_node(current_token, &token_list);
            free(current_token);
        }
    }
}

void    print_list(t_tokens *list)
{
    t_tokens *current_token;
    int     i;

    i = 0;
    current_token = list;
    while (current_token != NULL)
    {
        // printf("[%d]%s | Token Type: %d\n", i, current_token->value, current_token->type);
        i++;
        current_token = current_token->next;
    }
}

