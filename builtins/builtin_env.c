/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/14 16:22:58 by akant         #+#    #+#                 */
/*   Updated: 2021/11/14 16:33:26 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_env(char **envp)
{
	ft_print_split(envp, 0);
	return (0);
}
