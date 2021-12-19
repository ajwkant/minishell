/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 12:49:55 by akant         #+#    #+#                 */
/*   Updated: 2021/11/17 13:16:38 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include "libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_ast
{
	int				child_nodes;
	struct s_ast	*next;
}					t_ast;

// Builtin_cd.c
int		builtin_cd(char **envp, int *i);

// Builtin_echo.c
char	**copy_echopart_split(char **split, int *i);
int		builtin_echo(char **envp, char **split, int *i);

// Builtin_env.c
int		builtin_env(char **envp);

// Builtin_pwd.c
int		builtin_pwd(void);

// Error.c
int		error_return(char *str);

// Find_path.c
char	**find_paths(char **envp, char *start);
char	*make_path(char *cwd, char *path);
char	*check_access(char **paths, char *cmd);

// Is_env_var.c
int		is_env_var(char **envp, char **split, int *i);

// Is_simple_command.c
int		is_simple_command(char **envp, char **split, int *i);

// Loop.c
int		loop_shell_prompt(char **envp);

// Main.c
int		main(int argc, char **argv, char **envp);

#endif
