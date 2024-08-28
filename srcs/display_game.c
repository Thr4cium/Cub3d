/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:06:33 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/28 17:59:22 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int display_game(t_game *game)
{
    printf("pos_x : %f\n", game->pos_x);
    printf("pos_y : %f\n", game->pos_y);
    set_window_color(game, 0x00303030);
    print_minimap(game);
    //print_player(game, game->pos_x, game->pos_y, 10);
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
                draw_tile(game, start_x, start_y, 0x0077B5FE);
            start_x++;
        }
        start_y+= 1;
    }
}

// void    print_player(t_game *game, int x, int y, int r)
// {
//     double    i;
//     double    angle;
//     double    x1;
//     double    y1;

//     i = 0;
//     x1 = 0;
//     y1 = 0;
//     while (i < 360)
//     {
//         angle = i;
//         x1 = r * cos(angle * PI / 180);
//         y1 = r * sin(angle * PI / 180);
//         //draw_line(game, x, y, x1, y1);
//         i += 0.1;
//     }
// }

// void    draw_line(t_game *game, double x, double y, double x1, double y1)
// {
//     double  screenx;
//     double  screeny;
//     double  screenx1;
//     double  screeny1;
// }

void    draw_tile(t_game *game, double start_x, double start_y, int color)
{
    double  i;
    double  j;

    double center_x = SCREEN_WIDTH / 2;
    double center_y = SCREEN_HEIGHT / 2;

}
