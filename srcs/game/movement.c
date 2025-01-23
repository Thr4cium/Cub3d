/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:59:18 by rolamber          #+#    #+#             */
/*   Updated: 2025/01/23 22:34:04 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	rotate(t_game *game, float rotation_speed);

int	process_mouse_motion(t_game *game)
{
	int			x;
	int			y;
	int			delta_x;
	static int	last_x = SCREEN_WIDTH / 2;

	x = 0;
	y = 0;
	mlx_mouse_hide(game->mlx_ptr, game->win_ptr);
	mlx_mouse_get_pos(game->mlx_ptr, game->win_ptr, &x, &y);
	delta_x = x - last_x;
	if (delta_x > 0)
		game->mouse_x = 1;
	else if (delta_x < 0)
		game->mouse_x = -1;
	else
		game->mouse_x = 0;
	last_x = x;
	if (x >= SCREEN_WIDTH - 100 || x <= 100)
	{
		mlx_mouse_move(game->mlx_ptr, game->win_ptr, \
			SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		last_x = SCREEN_WIDTH / 2;
	}
	return (delta_x);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		game->keys->esc = true;
	if (keycode == XK_w || keycode == XK_z)
		game->keys->w = true;
	if (keycode == XK_s)
		game->keys->s = true;
	if (keycode == XK_a || keycode == XK_q)
		game->keys->a = true;
	if (keycode == XK_d)
		game->keys->d = true;
	if (keycode == XK_Left)
		game->keys->left = true;
	if (keycode == XK_Right)
		game->keys->right = true;
	if (keycode == XK_Escape || keycode == XK_w || keycode == XK_z
		|| keycode == XK_s || keycode == XK_a || keycode == XK_q
		|| keycode == XK_d || keycode == XK_Left || keycode == XK_Right)
		game->keys->is_pristine = false;
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		game->keys->esc = false;
	if (keycode == XK_w || keycode == XK_z)
		game->keys->w = false;
	if (keycode == XK_s)
		game->keys->s = false;
	if (keycode == XK_a || keycode == XK_q)
		game->keys->a = false;
	if (keycode == XK_d)
		game->keys->d = false;
	if (keycode == XK_Left)
		game->keys->left = false;
	if (keycode == XK_Right)
		game->keys->right = false;
	return (0);
}

void	move_mouse(t_game *game, t_move move, int delta_x)
{
	(void)move;
	rotate(game, delta_x * 0.001);
}
