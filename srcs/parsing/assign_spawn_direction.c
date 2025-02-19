/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_spawn_direction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:51:20 by magrondi          #+#    #+#             */
/*   Updated: 2025/01/27 02:20:46 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static	int	assign_angle_direction(t_game *game, float angle)
{
	float	plane_len;

	plane_len = 1;
	game->dir_x = cos((angle));
	game->dir_y = sin((angle));
	game->plane_x = (-game->dir_y * plane_len);
	game->plane_y = (game->dir_x * plane_len);
	return (1);
}

int	assign_spawn_direction(t_game *game, char direction)
{
	if (direction == 'N')
		return (assign_angle_direction(game, degrees_to_radians(NORTH_ANGLE)));
	else if (direction == 'S')
		return (assign_angle_direction(game, degrees_to_radians(SOUTH_ANGLE)));
	else if (direction == 'E')
		return (assign_angle_direction(game, degrees_to_radians(EAST_ANGLE)));
	else if (direction == 'W')
		return (assign_angle_direction(game, degrees_to_radians(WEST_ANGLE)));
	return (0);
}
