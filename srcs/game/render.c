/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:32:51 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/26 11:25:04 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	rotate(t_game *game, float rotation_speed);
void	move_player(t_game *game, float move_x, float move_y);

static	void	process_input(t_game *game)
{
	if (game->keys->esc)
		end_game(game);
	if (game->keys->w)
		move_player(game, game->dir_x, game->dir_y);
	if (game->keys->s)
		move_player(game, -game->dir_x, -game->dir_y);
	if (game->keys->a)
		move_player(game, -game->plane_x, -game->plane_y);
	if (game->keys->d)
		move_player(game, game->plane_x, game->plane_y);
	if (game->keys->left)
		rotate(game, -ROT_SPEED);
	if (game->keys->right)
		rotate(game, ROT_SPEED);
}

bool	is_there_wall(t_game *game, t_move move)
{
	int	x;
	int	y;

	if (move == UP)
	{
		x = game->pos_x + game->dir_x * 0.2;
		y = game->pos_y + game->dir_y * 0.2;
	}
	if (move == DOWN)
	{
		x = game->pos_x - game->dir_x * 0.2;
		y = game->pos_y - game->dir_y * 0.2;
	}
	if (game->map->map[(int)y][(int)x] == '1')
		return (true);
	return (false);
}

int	update_game(t_game *game)
{
	int	delta_x;

	if (BONUS && !game->keys->is_pristine)
	{
		delta_x = process_mouse_motion(game);
		if (game->mouse_x == -1)
			move_mouse(game, LEFT, delta_x);
		else if (game->mouse_x == 1)
			move_mouse(game, RIGHT, delta_x);
	}
	process_input(game);
	display_game(game);
	return (0);
}
