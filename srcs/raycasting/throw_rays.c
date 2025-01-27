/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:59:12 by magrondi          #+#    #+#             */
/*   Updated: 2025/01/27 04:09:39 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// int	get_color_test(t_texture *texture, t_rayon *ray, int x, int delta)
// {
// 	char	*ptr;
// 	int		color;
// 	int		texx;
// 	int		texy;
// 	int		y;

// 	texx = ray->wall_x * texture->width;
// 	if (ray->side == 0 && ray->tmp_dir_x > 0)
// 		texx = texture->width - texx - 1;
// 	if (ray->side == 1 && ray->tmp_dir_y < 0)
// 		texx = texture->width - texx - 1;
// 	if (delta > SCREEN_HEIGHT)
// 	{
// 		y = ((delta - SCREEN_HEIGHT) / 2) * texture->height / delta;
// 		texy = y + x * texture->height / delta;
// 	}
// 	else
// 		texy = x * texture->height / delta;
// 	ptr = texture->addr + (texy * texture->line_length + \
// 		texx * (texture->bits_per_pixel / 8));
// 	color = *(unsigned int *)ptr;
// 	return (color);
// }

// void	draw_scaled_wall_test(t_game *game, int x, t_rayon *ray)
// {
// 	int	color;
// 	int	delta;
// 	int	i;

// 	delta = ray->draw_end - ray->draw_start;
// 	if (ray->draw_start < 0)
// 		ray->draw_start = 0;
// 	if (ray->draw_end >= SCREEN_HEIGHT)
// 		ray->draw_end = SCREEN_HEIGHT - 1;
// 	i = 0;
// 	while (ray->draw_start < ray->draw_end)
// 	{
// 		if (ray->side == 1 && ray->step_y == -1)
// 			color = get_color_test(game->so_img, ray, i, delta);
// 		else if (ray->side == 1 && ray->step_y == 1)
// 			color = get_color_test(game->no_img, ray, i, delta);
// 		else if (ray->side == 0 && ray->step_x == -1)
// 			color = get_color_test(game->ea_img, ray, i, delta);
// 		else if (ray->side == 0 && ray->step_x == 1)
// 			color = get_color_test(game->we_img, ray, i, delta);
// 		secure_my_mlx_pixel_put2(game->img, x, ray->draw_start, color);
// 		i++;
// 		ray->draw_start++;
// 	}
// }

// // formule pour avoir le decalage B
// // x = Bx - Ax
// // y = By - Ay
// // exeple A(4;-2) B(3;3)
// // x = 3 - 4
// // le decalage sera de -1
// // y = 3 - (-2)
// // le decalage sera de 5
// void	compute_distance_and_side(t_game *game, t_rayon *rayon)
// {
// 	rayon->distance = sqrt(pow(game->pos_x - rayon->wall_x, 2)
// 			+ pow(game->pos_y - rayon->wall_y, 2));
// 	rayon->step_x = fabs(game->pos_x - rayon->wall_x);
// 	rayon->step_y = fabs(game->pos_y - rayon->wall_y);
// 	if (rayon->step_y > rayon->step_x)
// 		rayon->side = 1;
// 	else
// 		rayon->side = 0;
// 	if (rayon->distance == 0)
// 		rayon->distance = 1;
// 	rayon->draw_start = (SCREEN_HEIGHT / 2) - (rayon->wall_height / 2);
// 	rayon->draw_end = (SCREEN_HEIGHT / 2) + (rayon->wall_height / 2);
// 	rayon->wall_height = (SCREEN_HEIGHT / rayon->distance);
// }

// void	get_wall_position(t_game *game, t_rayon *rayon)
// {
// 	size_t	i;
// 	float	line_x;
// 	float	line_y;

// 	i = 0;
// 	while (1)
// 	{
// 		line_x = game->pos_x + (rayon->tmp_dir_x * i);
// 		line_y = game->pos_y + (rayon->tmp_dir_y * i);
// 		if (game->map->map
// 			[(int)(line_y)]
// 			[(int)(line_x)] == '1')
// 			break ;
// 		i ++;
// 	}
// 	rayon->wall_x = line_x;
// 	rayon->wall_y = line_y;
// }

// void	throw_ray(t_game *game)
// {
// 	t_rayon	ray;
// 	float	angle;
// 	float	half_fov;
// 	int		x;

// 	half_fov = degrees_to_radians(FOV / 2);
// 	angle = -half_fov;
// 	x = 0;
// 	while (x < SCREEN_WIDTH)
// 	{
// 		ray.tmp_dir_x = (game->dir_x * cos(angle))
// 			- (game->dir_y * sin(angle));
// 		ray.tmp_dir_y = (game->dir_y * cos(angle))
// 			+ (game->dir_x * sin(angle));
// 		get_wall_position(game, &ray);
// 		compute_distance_and_side(game, &ray);
// 		draw_scaled_wall_test(game, x, &ray);
// 		angle += ONE_DEGREE_IN_RADIANS;
// 		x ++;
// 	}
// }
