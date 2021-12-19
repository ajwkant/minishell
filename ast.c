/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ast.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/14 09:52:24 by akant         #+#    #+#                 */
/*   Updated: 2021/11/14 10:05:50 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ast_init(t_ast *ast)
{
	child_nodes = 0;
	next = NULL;
}

void	ast_add_child(t_ast *ast, t_ast *child)
{
	t_ast *temp;

	if (!ast || !child)
		return ;
	if (ast->child_nodes == 0)
		ast->next = (void *)child;
	else
	{
		temp = (t_ast *)ast->next;
		while (temp->next)
			temp = temp->next;
		temp->next = (void *)child;
	}
	ast->child_nodes++;
}
