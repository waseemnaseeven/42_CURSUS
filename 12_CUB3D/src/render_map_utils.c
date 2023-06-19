/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:26:12 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/06/07 11:23:53 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	get_color_value(void *img, int x, int y)
{
	unsigned int	*img_data;
	int				index;

	img_data = (unsigned int *)img;
	index = y * TEXWIDTH + x;
	return (img_data[index]);
}

int	convert_hexa_color(int red, int green, int blue)
{
	int	hex_value;

	hex_value = 0;
	hex_value |= red << 16;
	hex_value |= green << 8;
	hex_value |= blue;
	return (hex_value);
}

int	get_color(char *rgb)
{
	char	**s_rgb;
	int		r;
	int		g;
	int		b;
	int		color;

	s_rgb = ft_split(rgb, ',');
	r = ft_atoi(s_rgb[0]);
	g = ft_atoi(s_rgb[1]);
	b = ft_atoi(s_rgb[2]);
	color = convert_hexa_color(r, g, b);
	free_tab(s_rgb);
	return (color);
}

void	floor_color(t_data *data, int drawend, int x)
{
	int	y;
	int	color;

	color = get_color(data->textures[F]);
	y = drawend;
	while (y < SCREENHEIGHT)
	{
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}

void	ceiling_color(t_data *data, int drawstart, int x)
{
	int	y;
	int	color;

	color = get_color(data->textures[C]);
	y = 0;
	while (y < drawstart)
	{
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}
