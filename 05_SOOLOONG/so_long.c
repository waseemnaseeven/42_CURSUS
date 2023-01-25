/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:14:34 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/23 10:50:32 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	map;
	int		size;

	size = 0;
	if (ac < 2)
		ft_puterror1();
	else if (ac > 2)
		ft_puterror2();
	else if (ac == 2)
	{
		if (ft_checkfile_extension(av[1]) == -1)
			ft_puterror3();
		ft_open_verif_map(av[1], &size);
		ft_stats(&map);
		map.size = size;
		map.map = ft_creating_map(av[1], &map);
		ft_charcount(&map);
		ft_collectinfomap(&map);
		ft_pathfinding(av[1], &map);
		ft_render_map(&map);
		free_map(&map);
	}
	return (0);
}
