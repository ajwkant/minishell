/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_pwd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/14 15:28:40 by akant         #+#    #+#                 */
/*   Updated: 2021/11/14 15:32:27 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_pwd(void)
{
	char	cwd[256];
	write(1, cwd, ft_strlen(getcwd(cwd, sizeof(cwd))));
	write(1, "\n", 1);
	return (0);
}