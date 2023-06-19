/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:59:25 by aaudevar          #+#    #+#             */
/*   Updated: 2023/06/12 19:47:17 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <string.h>

# define GREEN_PIXEL 0xFF00
# define RED_PIXEL 0xCC0000
# define WHITE_PIXEL 0xFFFFFF
# define KAKI_PIXEL 0x333300
# define BLUESKY 0x00FFFF
# define ORANGE 0xFF8000

/* QWERTY */
# define W 119
# define S 115
# define A 97
# define D 100

/* AZERTY */
# define Z 122
# define Q 113

/* ARROWS */
# define LEFT_ARR 65361
# define UP_ARR 65362
# define RIGHT_ARR 65363
# define DOWN_ARR 65364

# define ESC 65307

# define LEFT_CLICK 1

# define SCREENWIDTH 1000
# define SCREENHEIGHT 500
# define BUFFER 100000
# define MINIWIDTH 200
# define MINIHEIGHT 100

# define PI 3.14159265359
# define FOV 60

# define TILE_SIZE 32

# define TEXWIDTH 64
# define TEXHEIGHT 64

# define NUM_CMDS 6

typedef enum e_type
{
	NO,
	SO,
	WE,
	EA,
	C,
	F,
	PROBLEM,
}	t_type;

typedef enum e_coord
{
	x = 0,
	y = 1,
}	t_coord;

typedef struct s_data
{
	char			*textures[6];
	char			**map;
	int				size_map;
	int				count_key;
	float			posx;
	float			posy;
	float			newposx;
	float			newposy;
	float			endx;
	float			endy;
	float			cols;
	float			rows;
	float			p_speed;
	char			starting_direction;
	char			*color_number;
	void			*mlx;
	void			*win;
	bool			cmds[NUM_CMDS];
	void			*image;
	char			*c_addr;
	int				*i_addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mini_img;
	char			*mini_addr;
	int				mini_bpp;
	int				mini_line_length;
	int				mini_endian;
	struct s_ray	*ray;
	struct s_img	*img;
}	t_data;

typedef struct s_img
{
	int		w;
	int		h;
	void	*img_no;
	char	*no_addr;
	int		no_bits_per_pixel;
	int		no_line_length;
	int		no_endian;
	int		texx;
	int		texy;
	double	wallx;
	double	step;
	double	texpos;
	int		y;
	void	*img_so;
	char	*so_addr;
	int		so_bits_per_pixel;
	int		so_line_length;
	int		so_endian;
	void	*img_ea;
	char	*ea_addr;
	int		ea_bits_per_pixel;
	int		ea_line_length;
	int		ea_endian;
	void	*img_we;
	char	*we_addr;
	int		we_bits_per_pixel;
	int		we_line_length;
	int		we_endian;

}	t_img;

typedef struct s_ray
{
	float	camerax;
	float	dirx;
	float	diry;
	float	olddirx;
	float	olddiry;
	int		mapx;
	int		mapy;
	float	deltadistx;
	float	deltadisty;
	float	planex;
	float	planey;
	float	oldplanex;
	float	oldplaney;
	float	raydirx;
	float	raydiry;
	int		stepx;
	int		stepy;
	float	sidedistx;
	float	sidedisty;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	float	time;
	float	oldtime;
	float	perpwalldist;
	int		x;
	bool	hitwall;
}					t_ray;

/* utils */

char			*gnl(int fd);
int				reset_gnl(int fd, char **argv);
void			display_map(char **map);
void			display_arr(char *textures[6]);
char			*ignore_empty_line(char *line, int fd);

/* free and exit */

int				free_exit(t_data *data, char *msg);
void			free_data(t_data *data);
int				exit_error(char *msg, char *file);

/*parsing map && textures*/

void			check_file_name(char *file);
void			check_element(int fd);
void			parse_element(int fd, char **argv, t_data *data);
char			*look_for_map(int fd);
void			ft_initialize(t_data *data);
void			ft_parsing(t_data *data, char *argv[], int fd);
void			map_size(int fd, char **argv, t_data *data);
void			parse_map(int fd, char **argv, t_data *data);
void			check_map_characters(t_data *data);
void			check_map_closed(t_data *data);
void			check_correct_texture(t_data *d);
void			player_orientation(t_data *data);
void			error_img(t_data *data, t_img *img);

/* init_window */

void			init_window(t_data *data);
void			draw_player(t_data *data);
void			draw_minimap(t_data *data);
int				draw_map3d(t_data *data);

/* render_map */

int				display_(t_data *data);
int				get_tex_color(char *texData, int texx, int texy, int bpp);
void			get_tex_x_y_pos(t_data *data);
void			wall_color(t_data *data, int x);

/* render_map_utils */

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
float			len_of_ray(float ray);
int				increment_or_not(double end, int start);
void			my_mlx_fill_rectangle(t_data *data, int x, int y, int colors);
unsigned int	get_color_value(void *img, int x, int y);
void			ceiling_color(t_data *data, int drawstart, int x);
void			floor_color(t_data *data, int drawend, int x);
void			free_tab(char	**tab);

/* function hook */

void			ft_hooks(t_data *data);
void			rotate_right(t_data *data);
void			rotate_left(t_data *data);
int				ft_keyboard_events(int key, t_data *data);
void			handle_events(t_data *data);

/* hooks_utils */

int				cross_exit(t_data *data);
void			left(t_data *data);
void			upper(t_data *data);
void			lower(t_data *data);
void			right(t_data *data);
int				fn_no_event(t_data *data);

#endif
