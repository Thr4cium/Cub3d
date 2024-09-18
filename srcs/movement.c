/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:59:18 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/18 17:50:22 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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

int process_mouse_motion(t_game *game)
{
    int x;
    int y;
    int delta_x;
    static int last_x = SCREEN_WIDTH / 2;

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
        mlx_mouse_move(game->mlx_ptr, game->win_ptr, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        last_x = SCREEN_WIDTH / 2;
    }
    return (delta_x);
}
// int mouse_input(int x, int y, t_game *game)
// {
//     mlx_mouse_hide(game->mlx_ptr, game->win_ptr);
//     mlx_mouse_get_pos(game->mlx_ptr, game->win_ptr, &x, &y);
    
//     mlx_mouse_move(game->mlx_ptr, game->win_ptr, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
//     return (0);
// }

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

void    move_mouse(t_game *game, t_move move, int delta_x)
{
    double old_dir_x;

    if (delta_x < 0)
        delta_x = -delta_x;
    if (move == RIGHT)
    {
        old_dir_x = game->dir_x;
        game->dir_x = (game->dir_x * cos(PI / 720 * delta_x) - game->dir_y * sin(PI / 720 * delta_x));
        game->dir_y = (old_dir_x * sin(PI / 720 * delta_x) + game->dir_y * cos(PI / 720 * delta_x));
    }
    if (move == LEFT)
    {
        old_dir_x = game->dir_x;
        game->dir_x = (game->dir_x * cos(-PI / 720 * delta_x) - game->dir_y * sin(-PI / 720 * delta_x));
        game->dir_y = (old_dir_x * sin(-PI / 720 * delta_x) + game->dir_y * cos(-PI / 720 * delta_x));
    }
}

void    move(t_game *game, t_move move)
{
    double old_dir_x;
    
    if (move == UP && !is_there_wall(game, UP))
    {
        game->pos_x += game->dir_x * 0.1;
        game->pos_y += game->dir_y * 0.1;
    }
    if (move == DOWN && !is_there_wall(game, DOWN))
    {
        game->pos_x -= game->dir_x * 0.1;
        game->pos_y -= game->dir_y * 0.1;
    }
    if (move == RIGHT)
    {
        old_dir_x = game->dir_x;
        game->dir_x = (game->dir_x * cos(PI / 45) - game->dir_y * sin(PI / 45));
        game->dir_y = (old_dir_x * sin(PI / 45) + game->dir_y * cos(PI / 45));
    }
    if (move == LEFT)
    {
        old_dir_x = game->dir_x;
        game->dir_x = (game->dir_x * cos(-PI / 45) - game->dir_y * sin(-PI / 45));
        game->dir_y = (old_dir_x * sin(-PI / 45) + game->dir_y * cos(-PI / 45));
    }
}

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
