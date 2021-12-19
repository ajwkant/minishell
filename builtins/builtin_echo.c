/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_echo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/14 10:09:32 by akant         #+#    #+#                 */
/*   Updated: 2021/11/16 14:47:33 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_echopart_split(char **split, int *i)
{
	int		j;
	char	**e_split;

	if (!split)
		return (NULL);
	while (split[*i] && ft_strcmp(split[*i], "|"))
		(*i)++;
	e_split = ft_calloc(*i + 1, sizeof(char *));
	if (!e_split)
		return (NULL);
	j = 0;
	while (j < *i)
	{
		e_split[j] = ft_strdup(split[j]);
		if (!e_split[j])
			return (NULL);
		j++;
	}
	e_split[j] = NULL;
	(*i)--;
	return (e_split);
}

int		builtin_echo(char **envp, char **split, int *i)
{
	char	**paths;
	char	*working_path;
	int		status;
	pid_t	child;
	char	**echo_split;

	paths = find_paths(envp, "PATH=");
	if (!paths)
		return (error_return("Error: Cannot find envp paths in echo\n"));
	working_path =  check_access(paths, "echo");
	if (!working_path)
		return (error_return("Error: Working path echo\n"));
	child = fork();
	if (child < 0)
		return (error_return("Error: Fork in echo\n"));
	echo_split = copy_echopart_split(split, i);
	if (!echo_split)
		return (error_return("Error: split in echo\n"));
	if (child == 0)
		execve(working_path, echo_split, envp); // Check returnvalue
	waitpid(child, &status, 0);
	return (0);
}
