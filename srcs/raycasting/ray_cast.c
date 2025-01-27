/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:13:34 by rolamber          #+#    #+#             */
/*   Updated: 2025/01/27 10:41:51 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	set_ray(t_ray *ray);

void	compute_wall_inf(t_rayon *ray, t_game *game)
{
	double fish_eye_correction;

	ray->wall_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = (SCREEN_HEIGHT / 2) - (ray->wall_height / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (SCREEN_HEIGHT / 2) + (ray->wall_height / 2);
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	(void)game;
	ray->step_x = ray->wall_x - game->pos_x;
	ray->step_y = ray->wall_y - game->pos_y;
	ray->perp_wall_dist = sqrt(pow(ray->wall_x - game->pos_x, 2)
		+ pow(ray->wall_y - game->pos_y, 2));
	fish_eye_correction = (game->dir_x * ray->tmp_dir_x + game->dir_y * ray->tmp_dir_y) /
		(sqrt(pow(game->dir_x, 2) + pow(game->dir_y, 2)) *
		 sqrt(pow(ray->tmp_dir_x, 2) + pow(ray->tmp_dir_y, 2)));
	ray->perp_wall_dist = (fish_eye_correction * ray->perp_wall_dist);
	ray->delta_dist_x = (ray->wall_x - game->pos_x) / ray->tmp_dir_x
		* ray->perp_wall_dist;
	ray->delta_dist_y = (ray->wall_height - game->pos_y) / ray->tmp_dir_y
		* ray->perp_wall_dist;
}

void	get_wall_position(t_game *game, t_rayon *ray)
{
	double	line_x;
	double	line_y;

	line_x = game->pos_x;
	line_y = game->pos_y;
	while (game->map->map[(int)line_y][(int)line_x] != '1')
	{
		line_x += ray->tmp_dir_x * 0.01;
		line_y += ray->tmp_dir_y * 0.01;
	}
	ray->wall_x = line_x;
	ray->wall_y = line_y;
}

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

void	draw_wall_test(t_game *game, t_rayon *ray, int x)
{
	int	start_y;
	int	end_y;
	int	color;
	int	wall_height;
	int	y;

	wall_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	start_y = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	end_y = (SCREEN_HEIGHT / 2) + (wall_height / 2);
	if (start_y < 0)
		start_y = 0;
	if (end_y >= SCREEN_HEIGHT)
		end_y = SCREEN_HEIGHT - 1;
	if (ray->side == 1)
		color = GRAY_COLOR;
	else
		color = WHITE_COLOR;
	y = start_y;
	while (y <= end_y)
	{
		my_mlx_pixel_put(game->img, x, y, color);
		y++;
	}
}

void	ray_casting(t_game *game)
{
	t_rayon		ray;
	int			x;
	double		half_fov_radians;
	double		camera_x;

	half_fov_radians = (60 * M_PI / 180.0) / 2.0;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = ((2.0 * x) / SCREEN_WIDTH - 1.0)
			* tan(half_fov_radians);
		ray.tmp_dir_x = (game->dir_x
				+ game->plane_x * camera_x);
		ray.tmp_dir_y = (game->dir_y
				+ game->plane_y * camera_x);
		get_wall_position(game, &ray);
		compute_wall_inf(&ray, game);
		draw_wall_test(game, &ray, x);
		x ++;
	}
}

void	init_ray(t_game *game, t_ray *ray)
{
	ray->map_x = (int)game->pos_x;
	ray->map_y = (int)game->pos_y;
	ray->step_y = 0;
	ray->step_x = 0;
	ray->side = 0;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->delta_dist_y == 0)
		ray->delta_dist_y = 1;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->ray_dir_x = ray->ray_dir_x ;
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
