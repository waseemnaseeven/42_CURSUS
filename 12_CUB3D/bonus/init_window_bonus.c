/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:43:34 by aaudevar          #+#    #+#             */
/*   Updated: 2023/06/19 12:12:18 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	error_img(t_data *data, t_img *img)
{
	if (img->img_no)
		mlx_destroy_image(data->mlx, img->img_no);
	if (img->img_so)
		mlx_destroy_image(data->mlx, img->img_so);
	if (img->img_ea)
		mlx_destroy_image(data->mlx, img->img_ea);
	if (img->img_we)
		mlx_destroy_image(data->mlx, img->img_we);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (data->ray)
		free(data->ray);
	if (data->img)
		free(data->img);
	free(data->bots);
	free(data->doors);
	free(data->sprites);
	exit(free_exit(data, "Problem with wall textures"));
}

void	init_wall_helper(t_data *data, t_img *img, int height, int width)
{
	img->img_ea = mlx_xpm_file_to_image(data->mlx, data->textures[EA],
			&height, &width);
	if (!img->img_ea)
		error_img(data, img);
	img->ea_addr = mlx_get_data_addr(img->img_ea, &(img->ea_bits_per_pixel),
			&(img->ea_line_length), &(img->ea_endian));
	img->img_we = mlx_xpm_file_to_image(data->mlx,
			data->textures[WE], &height, &width);
	if (!img->img_we)
		error_img(data, img);
	img->we_addr = mlx_get_data_addr(img->img_we, &(img->we_bits_per_pixel),
			&(img->we_line_length), &(img->we_endian));
}

void	init_wall(t_data *data, t_img *img)
{
	int	height;
	int	width;

	img->img_no = mlx_xpm_file_to_image(data->mlx,
			data->textures[NO], &height, &width);
	if (!img->img_no)
		error_img(data, img);
	img->no_addr = mlx_get_data_addr(img->img_no, &(img->no_bits_per_pixel),
			&(img->no_line_length), &(img->no_endian));
	img->img_so = mlx_xpm_file_to_image(data->mlx,
			data->textures[SO], &height, &width);
	if (!img->img_so)
		error_img(data, img);
	img->so_addr = mlx_get_data_addr(img->img_so, &(img->so_bits_per_pixel),
			&(img->so_line_length), &(img->so_endian));
	init_wall_helper(data, img, height, width);
}

void	init_sprites(t_data *data, t_sprites *sprites)
{
	int	h;
	int	w;

	sprites->troop_img = mlx_xpm_file_to_image(data->mlx,
			STORM, &h, &w);
	sprites->troop_addr = mlx_get_data_addr(sprites->troop_img,
			&(sprites->troop_bits_per_pixel),
			&(sprites->troop_line_length), &(sprites->troop_endian));
}

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		free_exit(data, "Problem with MLX init");
	data->win = mlx_new_window(data->mlx,
			SCREENWIDTH, SCREENHEIGHT, "TATOOINE");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(free_exit(data, "Problem with MLX Window"));
	}
	init_wall(data, data->img);
	data->image = mlx_new_image(data->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!data->image)
		error_img(data, data->img);
	data->c_addr = mlx_get_data_addr(data->image,
			&(data->bits_per_pixel), &(data->line_length), &(data->endian));
	data->mini_img = mlx_new_image(data->mlx, MINIWIDTH, MINIHEIGHT);
	if (!data->mini_img)
		error_img(data, data->img);
	data->mini_addr = mlx_get_data_addr(data->mini_img,
			&(data->mini_bpp), &(data->mini_line_length), &(data->mini_endian));
	ft_hooks(data);
	mlx_loop(data->mlx);
}
