/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:13:10 by edalexan          #+#    #+#             */
/*   Updated: 2024/10/23 14:23:07 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

//Ex for tokens type:
//'1' for command;
//'2' for argument;
//'3' for operator;

typedef struct s_token
{
	char	*value;
	int		type;
	struct s_token	*next;
}		t_tokens;

/*utils.c*/
/*built in */
void	ft_echo(char **arg);
void	ft_cd(t_tokens *token_list);

int     ft_strcmp(char *s1, char *s2);
char    *ft_strstr(char *s1, char *s2);
char    **ft_split(char const *s, char c);
char	*ft_strjoin_modified_for_export(char *s1, char *s2);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup_no_quote(char *s);
char	*verifying_env_variables(char *command);
void    process_input(char *command, t_tokens **token_list);
void    process_string_to_token(char *command, t_tokens **token_list);
void    print_list(t_tokens *list);
#endif
