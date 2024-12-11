/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:35:56 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/26 09:35:27 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	secure_my_mlx_pixel_put(t_my_img *img, int x, int y, int color)
{
	if (x >= 0 && x > 30 && x < (SCREEN_WIDTH / 4 + 30) \
		&& y >= 0 && y > 10 && y < (SCREEN_HEIGHT / 3))
	{
		my_mlx_pixel_put(img, x, y, color);
		return (0);
	}
	return (-1);
}

int	secure_my_mlx_pixel_put2(t_my_img *img, int x, int y, int color)
{
	if (x >= 0 && x > 30 && x < (SCREEN_WIDTH / 4 + 30) \
		&& y >= 0 && y > 10 && y < (SCREEN_HEIGHT / 3))
		return (-1);
	my_mlx_pixel_put(img, x, y, color);
	return (0);
}

void	draw_round(t_game *game, double x, double y, int r)
{
	double	i;
	double	x1;
	double	y1;

	i = 0;
	x1 = 0;
	y1 = 0;
	while (i < 360)
	{
		x1 = r * cos(i * PI / 180);
		y1 = r * sin(i * PI / 180);
		if (x1 <= 0)
			while (x1 <= 0)
				my_mlx_pixel_put(game->img, x + x1++, y + y1, 0x00FF0000);
		else
			while (x1 > 0)
				my_mlx_pixel_put(game->img, x + x1--, y + y1, 0x00FF0000);
		i += 0.1;
	}
}

void	print_player(t_game *game, int x, int y, int r)
{
	draw_round(game, x, y, r);
}

void	print_minimap_background(t_game *game, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < SCREEN_HEIGHT / 3)
	{
		i = 0;
		while (i < SCREEN_WIDTH / 4 + 30)
		{
			if (i == 31 || j == 11 || j == SCREEN_HEIGHT / 3 - 1)
				secure_my_mlx_pixel_put(game->img, i, j, 0x00FFFFFF);
			else
				secure_my_mlx_pixel_put(game->img, i, j, color);
			i++;
		}
		if (j > 10)
			my_mlx_pixel_put(game->img, i, j, 0x00FFFFFF);
		j++;
	}
}
