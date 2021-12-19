/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_env_var.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 12:16:51 by akant         #+#    #+#                 */
/*   Updated: 2021/11/16 13:27:58 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int		is_env_var(char **envp, char **split, int *i)
{
	int		j;
	int		key_len;

	if (split[0][*i] == '$' && !(split[0][*i + 1] == '?'))
	{
		j = 0;
		while (envp[j])
		{
			key_len = ft_strlen(split[*i]) - 1;
			if (!ft_strncmp(envp[j], split[*i] + 1, key_len) && envp[j][key_len] == '=')
				printf("%s\n", envp[j] + key_len + 1);
			j++;
		}
	}
	// else
	// {
	// 	expand to exitstatus of the most recently executed foreground pipeline
	// }
	return (0);
}
