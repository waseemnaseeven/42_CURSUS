/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:43:25 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/20 11:51:22 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_check_long_min_helper(char *cmd)
{
	if (cmd[8] > '3')
		return (1);
	else if (cmd[9] > '6')
		return (1);
	else if (cmd[10] > '8')
		return (1);
	else if (cmd[11] > '5')
		return (1);
	else if (cmd[12] > '4')
		return (1);
	else if (cmd[13] > '7')
		return (1);
	else if (cmd[14] > '7')
		return (1);
	else if (cmd[15] > '5')
		return (1);
	else if (cmd[16] > '8')
		return (1);
	else if (cmd[17] > '0')
		return (1);
	else if (cmd[18] > '8')
		return (1);
	return (0);
}

int	ft_check_long_min(char *cmd)
{
	if (ft_strlen(cmd) > 19)
		return (1);
	if (ft_strlen(cmd) == 19)
	{
		if (cmd[1] > '2')
			return (1);
		else if (cmd[2] > '2')
			return (1);
		else if (cmd[3] > '3')
			return (1);
		else if (cmd[4] > '3')
			return (1);
		else if (cmd[5] > '7')
			return (1);
		else if (cmd[6] > '2')
			return (1);
		else if (cmd[7] > '0')
			return (1);
		else if (ft_check_long_min_helper(cmd))
			return (1);
	}
	return (0);
}
