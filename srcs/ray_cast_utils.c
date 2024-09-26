/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:39:59 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/26 09:50:58 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	dda_algorithm(t_game *game, t_ray *ray)
{
	bool	hit;

	hit = false;
	while (hit == false)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (game->map->map[ray->mapY][ray->mapX] == '1')
			hit = true;
	}
	ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
	if (ray->side == 0)
		ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
}

void	define_wall_line(t_game *game, t_ray *ray, int x)
{
	int	lineheight;

	if (ray->side == 0)
		ray->wallX = game->pos_y + ray->perpWallDist * ray->Vdir_y;
	else
		ray->wallX = game->pos_x + ray->perpWallDist * ray->Vdir_x;
	ray->wallX -= floor(ray->wallX);
	ray->perpWallDist *= (cos(PI / 4 - (x * (PI / 2) / SCREEN_WIDTH)));
	lineheight = (int)(SCREEN_HEIGHT / ray->perpWallDist);
	ray->drawStart = -lineheight / 2 + SCREEN_HEIGHT / 2;
	ray->drawEnd = lineheight / 2 + SCREEN_HEIGHT / 2;
	draw_ground_and_sky(game, x, ray->drawStart, ray->drawEnd);
	draw_scaled_wall(game, x, ray);
}

void	draw_scaled_wall(t_game *game, int x, t_ray *ray)
{
	int	color;
	int	delta;
	int	i;

	delta = ray->drawEnd - ray->drawStart;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	if (ray->drawEnd >= SCREEN_HEIGHT)
		ray->drawEnd = SCREEN_HEIGHT - 1;
	i = 0;
	while (ray->drawStart < ray->drawEnd)
	{
		if (ray->side == 1 && ray->stepY == -1)
			color = get_color(game->no_img, ray, i, delta);
		else if (ray->side == 1 && ray->stepY == 1)
			color = get_color(game->so_img, ray, i, delta);
		else if (ray->side == 0 && ray->stepX == -1)
			color = get_color(game->we_img, ray, i, delta);
		else if (ray->side == 0 && ray->stepX == 1)
			color = get_color(game->ea_img, ray, i, delta);
		secure_my_mlx_pixel_put2(game->img, x, ray->drawStart, color);
		i++;
		ray->drawStart++;
	}
}

void	draw_ground_and_sky(t_game *game, int x, int drawStart, int drawEnd)
{
	int	i;

	i = 0;
	while (i < drawStart)
	{
		secure_my_mlx_pixel_put2(game->img, x, i, game->map->sky_color);
		i++;
	}
	i = drawEnd;
	while (i < SCREEN_HEIGHT)
	{
		secure_my_mlx_pixel_put2(game->img, x, i, game->map->ground_color);
		i++;
	}
}

int	get_color(t_texture *texture, t_ray *ray, int x, int delta)
{
	char	*ptr;
	int		color;
	int		texx;
	int		texy;
	int		y;

	texx = ray->wallX * texture->width;
	if (ray->side == 0 && ray->Vdir_x > 0)
		texx = texture->width - texx - 1;
	if (ray->side == 1 && ray->Vdir_y < 0)
		texx = texture->width - texx - 1;
	if (delta > SCREEN_HEIGHT)
	{
		y = ((delta - SCREEN_HEIGHT) / 2) * texture->height / delta;
		texy = y + x * texture->height / delta;
	}
	else
		texy = x * texture->height / delta;
	ptr = texture->addr + (texy * texture->line_length + \
		texx * (texture->bits_per_pixel / 8));
	color = *(unsigned int *)ptr;
	return (color);
}
