/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:06:33 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/28 20:41:47 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int display_game(t_game *game)
{
    printf("pos_x : %f\n", game->pos_x);
    printf("pos_y : %f\n", game->pos_y);
    set_window_color(game, 0x00303030);
    print_minimap(game);
    printf("tile_size : %d\n", game->tile_size);
    print_player(game, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 41);
    //print_rays(game);
    sleep(3);
    return (0);
}

void    set_window_color(t_game *game, int color)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < SCREEN_WIDTH)
    {
        j = 0;
        while (j < SCREEN_HEIGHT)
        {
            mlx_pixel_put(game->mlx_ptr, game->win_ptr, i, j, color);
            j++;
        }
        i++;
    }
}

void    print_minimap(t_game *game)
{
    double start_x;
    double start_y;

    start_x = game->pos_x - MINIMAP_RANGE;
    start_y = game->pos_y - MINIMAP_RANGE;
    if (start_x < 0)
        start_x = 0;
    if (start_y < 0)
        start_y = 0;
    while (game->map->map[(int)start_y] && start_y < game->pos_y + MINIMAP_RANGE)
    {
        start_x = game->pos_x - MINIMAP_RANGE;
        while (game->map->map[(int)start_y][(int)start_x] && start_x < game->pos_x + MINIMAP_RANGE)
        {
            printf("start_y : %f start_x : %f \n", start_y, start_x);
            if (game->map->map[(int)start_y][(int)start_x] == '1')
                draw_tile(game, start_x - game->pos_x, start_y - game->pos_y, 0x0077B5FE);
            start_x++;
        }
        start_y+= 1;
    }
}

void    print_player(t_game *game, int x, int y, int r)
{
    draw_round(game, x, y, r, 0x00FF0000);
}

// void    draw_line(t_game *game, double x, double y, double x1, double y1)
// {
//     double  screenx;
//     double  screeny;
//     double  screenx1;
//     double  screeny1;
// }

void    draw_tile(t_game *game, double start_x, double start_y, int color)
{
    int     i;
    int     j;

    double center_x = SCREEN_WIDTH / 2;
    double center_y = SCREEN_HEIGHT / 2;
    start_x = center_x + start_x * game->tile_size;
    start_y = center_y + start_y * game->tile_size;
    i = 0;
    while (i < game->tile_size)
    {
        j = 0;
        while (j < game->tile_size)
        {
            mlx_pixel_put(game->mlx_ptr, game->win_ptr, start_x + i, start_y + j, color);
            j++;
        }
        i++;
    }
}

void    draw_round(t_game *game, double x, double y, int r, int color)
{
    double    i;
    double    x1;
    double    y1;

    i = 0;
    x1 = 0;
    y1 = 0;
    while (i < 360)
    {
        x1 = r * cos(i * PI / 180);
        y1 = r * sin(i * PI / 180);
        if (x1 <= 0)
            while(x1 <= 0)
            {
                mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + x1, y + y1, color);
                x1++;
            }
        else
            while (x1 > 0)
            {
                mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + x1, y + y1, color);
                x1--;
            }
        i += 0.1;
    }
}
