/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:32:51 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/26 08:33:39 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

bool    is_there_wall(t_game *game, t_move move)
{
    int x;
    int y;

    x = game->pos_x + game->dir_x * 0.1;
    y = game->pos_y + game->dir_y * 0.1;
    if (move == UP)
    {
        x = game->pos_x + game->dir_x * 0.1;
        y = game->pos_y + game->dir_y * 0.1;
    }
    if (move == DOWN)
    {
        x = game->pos_x - game->dir_x * 0.1;
        y = game->pos_y - game->dir_y * 0.1;
    }
    if (game->map->map[(int)y][(int)x] == '1')
        return (true);
    return (false);
}

int update_game(t_game *game)
{
    int delta_x;

    delta_x = process_mouse_motion(game);
    if (game->keys[XK_w])
        move(game, UP);
    if (game->keys[XK_s])
        move(game, DOWN);
    if (game->keys[XK_a])
        move(game, LEFT);
    if (game->keys[XK_d])
        move(game, RIGHT);
    if (game->mouse_x == -1)
        move_mouse(game, LEFT, delta_x);
    else if (game->mouse_x == 1)
        move_mouse(game, RIGHT, delta_x);
    display_game(game);
    return (0);
}
