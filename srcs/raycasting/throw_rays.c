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



void	throw_ray(t_game *game)
{
	t_ray	ray;
	float	angle;
	float	half_fov;
	float	tmp_dir_x;
	float	tmp_dir_y;

	half_fov = degrees_to_radians(FOV / 2);
	angle = -half_fov;
	while (angle <= half_fov)
	{
		tmp_dir_x = (game->dir_x * cos(angle))
			- (game->dir_y * sin(angle));
		tmp_dir_y = (game->dir_y * cos(angle))
			+ (game->dir_x * sin(angle));
		// get len of ray
		angle += ONE_DEGREE_IN_RADIANS;
	}
}
