/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:10:49 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/20 15:27:11 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stddef.h>
# include <fcntl.h>

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	int		size;
	char	**map;
	int		cols;
	int		rows;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		collectible;
	int		direction;
	int		end_game;
	int		n_collect;
	int		move;
	int		e;
	int		c;
	int		p;
}	t_game;

typedef struct s_img
{
	int		w;
	int		h;
}	t_img;

/* ***** Hooks functions ***** */
int		cross_exit(t_game *map);
void	key_error(t_game *map);
int		ft_key_events(t_game *map, int py, int px, int direction);
int		ft_keyboard_events(int key, t_game *map);
void	ft_hook(t_game *map);

/* ***** Parsing functions ***** */
int		ft_map_line_len(char *line);
void	ft_check_middle(char *line);
void	ft_check_horizontal(char *line);
void	ft_check_foreign_char(char *line);
void	ft_check_is_rectangular(char *line);
int		ft_countmap(char *line);
void	ft_check_charerror(t_game *map);
void	ft_charcount(t_game *map);
void	ft_verif_map(int fd, int *size);
void	ft_open_verif_map(char *file, int *size);

/* ***** Creating map functions ***** */
char	**ft_creating_map(char *file, t_game *map);
char	**ft_close_file(int fd, char **ret[]);

/* ***** Render map functions ***** */
void	ft_rendertile(t_game *map, void *r_tile, t_img tile);
void	ft_renderwalls(t_game *map, void *r_tile, t_img tile);
void	ft_renderkyubi(t_game *map, void *r_tile, t_img tile);
void	ft_renderplayer(t_game *map, void *r_tile, t_img tile);
void	ft_renderexit(t_game *map, void *r_tile, t_img tile);
void	ft_put_wallfloor(t_game *map);
void	ft_put_sprites(t_game *map);
void	ft_render_map(t_game *map);

/* ***** Info_map ***** */
void	ft_stats(t_game *map);
void	ft_pathfinding(char *file, t_game *map);
void	ft_patherror(t_game *map);
void	ft_collectinfomap(t_game *map);
void	ft_collectinfomap2(t_game *map, int y, int x);

/* ***** Pathfinding functions ***** */
void	ft_pathfinding(char *file, t_game *map);
void	load_good_map(char *file, t_game *map);
int		ft_checkpathfinding(t_game *map);
void	put_cross_map(t_game *map);
void	p_line(t_game *map);
void	before_pathfinding(t_game *map, int p_y, int p_x);
void	put_cross(t_game *map, int y, int x);
void	put_cross_x(t_game *map, int y, int x);
void	put_cross_y(t_game *map, int y, int x);
void	ft_patherror(t_game *map);

/* ***** Utils functions ***** */
void	ft_print_map(t_game map);
void	ft_puterror1(void);
void	ft_puterror2(void);
void	ft_puterror3(void);
int		ft_checkfile_extension(char *file);
void	free_line(char *line);
void	display(char **map);
void	ft_print_map(t_game map);
void	free_map(t_game *map);
void	full_free(t_game *map);

/* ***** Player movements functions ***** */
int		ft_close_window(t_game *map);
void	ft_move_player(t_game *map, int y, int x);
void	ft_swap_tiles(char *tile1, char *tile2);
void	ft_swap_exit(char *tile1, char *tile2);
void	ft_remove_collectible(char *player, char *collectible);
void	ft_remove_exit(char *player, char *exit);

#endif
