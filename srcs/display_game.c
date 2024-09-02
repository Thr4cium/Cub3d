/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:06:33 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/02 14:36:22 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int display_game(t_game *game)
{
    set_window_color(game, 0x00303030);
    print_minimap(game);
    print_player(game, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 41);
    draw_line(game, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0x0090EE90);
    //print_rays(game);
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

    
    start_x = (int)game->pos_x - MINIMAP_RANGE;
    start_y = (int)game->pos_y - MINIMAP_RANGE;
    if (start_x < 0)
        start_x = 0;
    if (start_y < 0)
        start_y = 0;
    while (game->map->map[(int)start_y] && start_y < game->pos_y + MINIMAP_RANGE)
    {
        start_x = (int)(game->pos_x - MINIMAP_RANGE);
        while (game->map->map[(int)start_y][(int)start_x] && start_x < game->pos_x + MINIMAP_RANGE)
        {
            if (game->map->map[(int)start_y][(int)start_x] == '1')
            {
                printf("start_x : %f pos x %f\n", start_x , game->pos_x);
                printf ("start_y : %f pos y %f\n", start_y, game->pos_y);
                draw_tile(game, start_x - game->pos_x, start_y - game->pos_y, 0x0077B5FE);
            }
            start_x+= 1;
        }
        start_y+= 1;
    }
}

void    print_player(t_game *game, int x, int y, int r)
{
    draw_round(game, x, y, r, 0x00FF0000);
}

void    draw_line(t_game *game, int x, int y, int color)
{
    int i;

    i = 0;
    while (i < 60)
    {
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + game->dir_x * i, y + game->dir_y * i, color);
        i++;
    }
}

void    draw_tile(t_game *game, double start_x, double start_y, int color)
{
    int     i;
    int     j;

    double center_x = (double)SCREEN_WIDTH / 2;
    double center_y = SCREEN_HEIGHT / 2;
    start_x = (double)(center_x + start_x * game->tile_size);
    start_y = (double)(center_y + start_y * game->tile_size);
    i = 0;
    while (i < game->tile_size)
    {
        j = 0;
        while (j < game->tile_size)
        {
            my_mlx_pixel_put(game->mlx_ptr, game->win_ptr, start_x + i, start_y + j, color);
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

int my_mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
    if (x >= 0 && x > SCREEN_WIDTH / 3 && x < ((SCREEN_WIDTH * 2 )/ 3) && y >= 0 && y > SCREEN_HEIGHT / 3)
    { 
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
        return (0);
    }
    return ( -1);
}
