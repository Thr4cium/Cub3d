/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:59:12 by magrondi          #+#    #+#             */
/*   Updated: 2025/01/24 02:25:29 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void draw_wall_test(t_game *game, t_rayon *rayon, int x)
{
	int	start;
	int	end;
	int	y;
	int	color;

	start = (SCREEN_HEIGHT / 2) - (rayon->wall_height / 2);
	end = (SCREEN_HEIGHT / 2) + (rayon->wall_height / 2);
    if (start < 0)
        start = 0;
    if (end >= SCREEN_HEIGHT)
        end = SCREEN_HEIGHT - 1;
    if (rayon->side == 1)
		color = 0xAAAAAA;
	else
		color = 0xFFFFFF;
    y = start;
    while (y <= end)
    {
        my_mlx_pixel_put(game->img, x, y, color);
        y++;
    }
}

// formule pour avoir le decalage B
// x = Bx - Ax
// y = By - Ay
// exeple A(4;-2) B(3;3)
// x = 3 - 4
// le decalage sera de -1
// y = 3 - (-2)
// le decalage sera de 5
void	compute_distance_and_side(t_game *game, t_rayon *rayon)
{
	rayon->distance = sqrt(pow(game->pos_x - rayon->wall_x, 2)
			+ pow(game->pos_y - rayon->wall_y, 2));
	rayon->step_x = fabs(game->pos_x - rayon->wall_x);
	rayon->step_y = fabs(game->pos_y - rayon->wall_y);
	if (rayon->step_y > rayon->step_x)
		rayon->side = 1;
	else
		rayon->side = 0;
	if (rayon->distance == 0)
		rayon->distance = 1;
	rayon->wall_height = (SCREEN_HEIGHT / rayon->distance);
}

void	get_wall_position(t_game *game, t_rayon *rayon)
{
	size_t	i;
	float	line_x;
	float	line_y;

	i = 0;
	while (1)
	{
		line_x = game->pos_x + (rayon->tmp_dir_x * i);
		line_y = game->pos_y + (rayon->tmp_dir_y * i);
		if (game->map->map
			[(int)(line_y)]
			[(int)(line_x)] == '1')
			break ;
		i ++;
	}
	rayon->wall_x = line_x;
	rayon->wall_y = line_y;
}

void	throw_ray(t_game *game)
{
	t_rayon	ray;
	float	angle;
	float	half_fov;

	half_fov = degrees_to_radians(FOV / 2);
	angle = -half_fov;
	while (angle <= half_fov)
	{
		ray.tmp_dir_x = (game->dir_x * cos(angle))
			- (game->dir_y * sin(angle));
		ray.tmp_dir_y = (game->dir_y * cos(angle))
			+ (game->dir_x * sin(angle));
		get_wall_position(game, &ray);
		angle += ONE_DEGREE_IN_RADIANS;
	}
}
