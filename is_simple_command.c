/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_simple_command.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:09:19 by akant         #+#    #+#                 */
/*   Updated: 2021/11/17 14:43:59 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_simple_command(char **envp, char **split, int *i) // This is not done yet
{
	char	**paths;
	char	*working_path;
	int		status;
	pid_t	child;
	char	**echo_split;

	paths = find_paths(envp, "PATH=");
	if (!paths)
		return (error_return("Error: Cannot find envp path in simple command\n"));
	working_path =  check_access(paths, split[*i]);
	if (!working_path)
		return (error_return("Error: Working path simple command\n"));
	child = fork();
	if (child < 0)
		return (error_return("Error: Fork in simple command\n"));
	echo_split = copy_echopart_split(split, i); // Adjust to fit all possible arguments
	if (!echo_split)
		return (error_return("Error: split in simple command\n"));
	if (child == 0)
		execve(working_path, echo_split, envp); // Check returnvalue
	waitpid(child, &status, 0);
	return (0);
}