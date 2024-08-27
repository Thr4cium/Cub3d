/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:06:33 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/27 17:06:16 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int display_game(t_game *game)
{
    print_minimap(game);
    print_player(game, game->pos_x, game->pos_y, 10);
    //print_rays(game);
    return (0);
}

void    print_minimap(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (game->map->map[i])
    {
        j = 0;
        while (game->map->map[i][j])
        {
            if (game->map->map[i][j] == '1')
                mlx_pixel_put(game->mlx_ptr, game->win_ptr, j, i, 0x00FFFFFF);
            j++;
        }
        i++;
    }        
}

void    print_player(t_game *game, int x, int y, int r)
{
    double    i;
    double    angle;
    double    x1;
    double    y1;

    i = 0;
    x1 = 0;
    y1 = 0;
    while (i < 360)
    {
        angle = i;
        x1 = r * cos(angle * PI / 180);
        y1 = r * sin(angle * PI / 180);
        draw_line(game, x, y, x1, y1);
        i += 0.1;
    }
}

void    draw_line(t_game *game, int x, int y, double x1, double y1)
{
    double    x2;
    double    y2;
    double    dx;
    double    dy;
    double    step;
    double    i;

    i = 0;
    x2 = x + x1;
    y2 = y + y1;
    dx = x2 - x;
    dy = y2 - y;
    if (fabs(dx) > fabs(dy))
        step = fabs(dx);
    else
        step = fabs(dy);
    dx /= step;
    dy /= step;
    while (i <= step)
    {
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, 0x00FF0000);
        x += dx;
        y += dy;
        i++;
    }
}

