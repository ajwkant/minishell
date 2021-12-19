/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_cd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/14 11:45:53 by akant         #+#    #+#                 */
/*   Updated: 2021/11/14 14:58:37 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_cd(char **split, int *i)
{
	char	*path;
	char	cwd[256];

	getcwd(cwd, sizeof(cwd));
	path = make_path(cwd, split[*i + 1]);
	if (chdir(path) == -1)
		return (error_return("Error: Changing directory failed\n"));
	(*i)++;
	free(path);
	return (0);
}
