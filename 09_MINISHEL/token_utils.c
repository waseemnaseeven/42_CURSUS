/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:45:17 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/16 14:43:16 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	is_sep(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v'
		|| c == '\f' || c == '\n' || c == '|' || c == '<'
		|| c == '>')
		return (1);
	else
		return (0);
}

int	is_redirection(char c)
{
	if (c == '<' || c == '>')
		return (1);
	else
		return (0);
}

int	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v'
		|| c == '\f' || c == '\n')
		return (1);
	else
		return (0);
}

int	ft_is_quote(char c, char quote)
{
	if (!c)
		return (0);
	if (c != quote)
		return (1);
	else
		return (0);
}

void	ft_token_copy_quote(t_data *data, char **temp, int *j, char c)
{
	(*temp)[*j] = data->input[data->index + *j];
	(*j)++;
	while (ft_is_quote(data->input[data->index + *j], c))
	{
		(*temp)[*j] = data->input[data->index + *j];
		(*j)++;
	}
	if (data->input[data->index + *j] == c)
	{
		(*temp)[*j] = data->input[data->index + *j];
		(*j)++;
	}
}
