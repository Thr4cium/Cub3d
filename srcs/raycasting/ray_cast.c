/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:13:34 by rolamber          #+#    #+#             */
/*   Updated: 2025/01/24 00:35:41 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	set_ray(t_ray *ray);

void	print_minimap_perp_rays(t_game *game)
{
	int		i;
	double	x_0;
	double	y_0;
	double	x_dir;
	double	y_dir;

	i = 0;
	x_0 = (SCREEN_WIDTH / 7.1) + game->dir_x * 120;
	y_0 = (SCREEN_HEIGHT / 5.8) + game->dir_y * 120;
	x_dir = (game->dir_x * cos(M_PI / 2) - game->dir_y * sin(M_PI / 2));
	y_dir = (game->dir_x * sin(M_PI / 2) + game->dir_y * cos(M_PI / 2));
	while (i < 60)
	{
		my_mlx_pixel_put(game->img, x_0 + x_dir * i, y_0 + y_dir * i, GREEN);
		i++;
	}
	x_dir = (game->dir_x * cos(-M_PI / 2) - game->dir_y * sin(-M_PI / 2));
	y_dir = (game->dir_x * sin(-M_PI / 2) + game->dir_y * cos(-M_PI / 2));
	i = 0;
	while (i < 60)
	{
		my_mlx_pixel_put(game->img, x_0 + x_dir * i, y_0 + y_dir * i, GREEN);
		i++;
	}
}

void	ray_casting(t_game *game)
{
	t_ray		ray;
	int			x;
	double		half_fov_radians;
	double		camera_x;

	half_fov_radians = (60 * M_PI / 180.0) / 2.0;
	x = 0;
	set_ray(&ray);
	while (x < SCREEN_WIDTH)
	{
		camera_x = ((2.0 * x) / SCREEN_WIDTH - 1.0)
			* tan(half_fov_radians);
		ray.ray_dir_x = (game->dir_x
				+ game->plane_x * camera_x);
		ray.ray_dir_y = (game->dir_y
				+ game->plane_y * camera_x);
		ray_cast(game, &ray, x);
		x ++;
	}
}

int	ray_cast(t_game *game, t_ray *ray, int i)
{
	init_ray(game, ray);
	dda_algorithm(game, ray);
	define_wall_line(game, ray, i);
	return (0);
}

void	init_ray(t_game *game, t_ray *ray)
{
	ray->map_x = (int)game->pos_x;
	ray->map_y = (int)game->pos_y;
	ray->step_y = 0;
	ray->step_x = 0;
	ray->side = 0;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->delta_dist_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->ray_dir_x = ray->ray_dir_x ;
	ray->ray_dir_y = ray->ray_dir_y;
	init_ray2(game, ray);
}

void	init_ray2(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->pos_y) * ray->delta_dist_y;
	}
}
