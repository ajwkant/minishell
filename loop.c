/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/12 11:17:21 by akant         #+#    #+#                 */
/*   Updated: 2021/11/17 13:09:04 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_builtin(char **envp, char **split, int *i) // make all the run functions and returnvalues
{
	if (ft_strcmp(split[*i], "echo") == 0)
		builtin_echo(envp, split, i);
	else if (ft_strcmp(split[*i], "cd") == 0) // with relative or absolute path
		builtin_cd(split, i);
	else if (ft_strcmp(split[*i], "pwd") == 0)
		builtin_pwd();
	// else if (ft_strcmp(split[*i], "export") == 0)
	// 	run_export();
	// else if (ft_strcmp(split[*i], "unset") == 0)
	// 	run_unset();
	else if (ft_strcmp(split[*i], "env") == 0)
		builtin_env(envp);
	else if (ft_strcmp(split[*i], "exit") == 0)
		return (1);
	return (0);
}

void		run_split(char **split, char **envp)
{
	int i;

	i = 0;
	while (split[i])
	{
		if (is_builtin(envp, split, &i) == 1) // Two builtins still to build
			exit(EXIT_SUCCESS);// return (1);
		// is_single_quote(split, i); // Still to make
		// is_double_quote(split, i); // Still to make
		if (is_env_var(envp, split, &i)) // check returnvalue
			exit(EXIT_SUCCESS); // '$?' still to make
		// is_ctrl(split, i); // Still to make
		// What to do with redirect
		if (is_simple_command(envp, split, &i)) // Check returnvalue
			exit(EXIT_SUCCESS);
		i++;
	}
}

int		loop_shell_prompt(char **envp)
{
	char	*line;
	char	**split;
	char	*prompt;

	line = (char *)1;
	prompt = ft_strdup("> ");
	if (!prompt)
		return (1); // Failure
	while (line)
	{
		line = readline(prompt);
		if (line && *line) // test this still
			add_history(line);
		split = ft_split(line, ' '); // Should maybe also split on other whitespace characters
		if (!split)
			return (-1); // Some error management here
		run_split(split, envp); // check returnvalue

		ft_split_free(split);
		free(line);
	}
	return (0);
}
