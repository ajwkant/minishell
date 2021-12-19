/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/14 10:23:05 by akant         #+#    #+#                 */
/*   Updated: 2021/11/16 13:12:06 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" // check returnvalues van substr etc

char	*find_line_starting_with(char **envp, char *start)
{
	while (ft_strncmp(*envp, start, 5))
		envp++;
	return (*envp);
}

char	**find_paths(char **envp, char *start)
{
	char	*path_start;
	char	*path_copy;
	char	**all_paths;

	path_start = find_line_starting_with(envp, start);
	path_copy = ft_substr(path_start, 5, ft_strlen(path_start) - 5);
	all_paths = ft_split(path_copy, ':');
	free(path_copy);
	return (all_paths);
}

char	*make_path(char *cwd, char *path)
{
	char *str_slash;
	char *str;

	str_slash = ft_strjoin(cwd, "/");
	if (!str_slash)
		return (NULL);
	str = ft_strjoin(str_slash, path);
	if (!str)
		return (NULL);
	free(str_slash);
	return (str);
}

char	*check_access(char **paths, char *cmd)
{
	char *str;

	str = make_path(*paths, cmd);
	while (!(access(str, F_OK) == 0 && access(str, X_OK) == 0))
	{
		free(str);
		paths++;
		if (!*paths)
			return (NULL);
		str = make_path(*paths, cmd);
	}
	return (str);
}