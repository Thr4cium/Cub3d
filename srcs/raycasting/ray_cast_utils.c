/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:39:59 by rolamber          #+#    #+#             */
/*   Updated: 2024/12/12 15:21:45 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	dda_algorithm(t_game *game, t_ray *ray)
{
	bool	hit;

	hit = false;
	while (hit == false)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map->map[ray->map_y][ray->map_x] == '1')
			hit = true;
	}
	ray->perp_wall_dist = (ray->map_y - game->pos_y
			+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->pos_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
}

void	define_wall_line(t_game *game, t_ray *ray, int x)
{
	int	lineheight;

	if (ray->side == 0)
		ray->wall_x = game->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	lineheight = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -lineheight / 2 + SCREEN_HEIGHT / 2;
	ray->draw_end = lineheight / 2 + SCREEN_HEIGHT / 2;
	draw_ground_and_sky(game, x, ray->draw_start, ray->draw_end);
	draw_scaled_wall(game, x, ray);
}

void	draw_scaled_wall(t_game *game, int x, t_ray *ray)
{
	int	color;
	int	delta;
	int	i;

	delta = ray->draw_end - ray->draw_start;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	i = 0;
	while (ray->draw_start < ray->draw_end)
	{
		if (ray->side == 1 && ray->step_y == -1)
			color = get_color(game->so_img, ray, i, delta);
		else if (ray->side == 1 && ray->step_y == 1)
			color = get_color(game->no_img, ray, i, delta);
		else if (ray->side == 0 && ray->step_x == -1)
			color = get_color(game->ea_img, ray, i, delta);
		else if (ray->side == 0 && ray->step_x == 1)
			color = get_color(game->we_img, ray, i, delta);
		secure_my_mlx_pixel_put2(game->img, x, ray->draw_start, color);
		i++;
		ray->draw_start++;
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

	texx = ray->wall_x * texture->width;
	if (ray->side == 0 && ray->ray_dir_x > 0)
		texx = texture->width - texx - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
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
