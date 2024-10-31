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
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

/*utils.c*/
int     ft_strcmp(char *s1, char *s2);
char    *ft_strstr(char *s1, char *s2);
char    **ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_modified_for_export(char *s1, char *s2);

#endif
