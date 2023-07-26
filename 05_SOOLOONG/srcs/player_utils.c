/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:41:54 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/26 18:22:04 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap_tiles(char *tile1, char *tile2)
{
	char	tmp;

	tmp = *tile1;
	*tile1 = *tile2;
	*tile2 = tmp;
}

void	ft_swap_exit(char *player, char *exit)
{
	char	e;
	char	p;
	//char	zero;

	e = *exit;
	p = *player;
	//zero = '0';
	*exit = p;
	*player = e;
}

void	ft_remove_collectible(char *player, char *collectible)
{
	*collectible = *player;
	*player = '0';
}

void	ft_remove_exit(char *player, char *exit)
{
	*exit = *player;
	*player = '0';
}
