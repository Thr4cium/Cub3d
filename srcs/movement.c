/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:59:18 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/02 13:54:18 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int update_game(t_game *game)
{
    if (game->keys[XK_w])
        move(game, UP);
    if (game->keys[XK_s])
        move(game, DOWN);
    if (game->keys[XK_a])
        move(game, LEFT);
    if (game->keys[XK_d])
        move(game, RIGHT);
    display_game(game);
    return (0);
}


int key_input(int keycode, t_game *game)
{
    if (keycode == XK_Escape)
        end_game(game);
    if (keycode >= 0 && keycode < 256)
    {
        game->key_pressed = true;
        game->keys[keycode] = true;
    }
    return (0);
}

int key_release(int keycode, t_game *game)
{
    if (keycode >= 0 && keycode < 256)
    {
        game->key_pressed = false;
        game->keys[keycode] = false;
    }
    return (0);
}
void    move(t_game *game, t_move move)
{
    if (move == UP)
    {
       game->pos_x += game->dir_x * 0.1;
       game->pos_y += game->dir_y * 0.1;
    }
    if (move == DOWN)
    {
        game->pos_x -= game->dir_x * 0.1;
        game->pos_y -= game->dir_y * 0.1;
    }
    if (move == RIGHT)
    {
        game->dir_x = (game->dir_x * cos(PI / 180) - game->dir_y * sin(PI / 180));
        game->dir_y = (game->dir_x * sin(PI /180) + game->dir_y * cos(PI / 180));
    }
    if (move == LEFT)
    {
        game->dir_x = (game->dir_x * cos(-PI / 180) - game->dir_y * sin(-PI / 180));
        game->dir_y = (game->dir_x * sin(-PI / 180) + game->dir_y * cos(-PI / 180));
    }
}
