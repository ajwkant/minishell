/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/12 11:15:28 by akant         #+#    #+#                 */
/*   Updated: 2021/11/14 10:25:23 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	argc = 0;
	argv = NULL;
	// INIT

	// LOOP
	loop_shell_prompt(envp); // check returnvalue

	// TERMINATE
}