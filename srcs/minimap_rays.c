/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:39:59 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/04 16:27:01 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../headers/cub3d.h"

void    print_rays(t_game *game)
{
    int i;
    double x0;
    double y0;
    double xdir;
    double ydir;

    i = 0;
    x0 =  (SCREEN_WIDTH / 7.1) + game->dir_x * 120;
    y0 =  (SCREEN_HEIGHT / 5.8) + game->dir_y * 120;
    xdir = (game->dir_x * cos(PI / 2) - game->dir_y * sin(PI / 2));
    ydir = (game->dir_x * sin(PI / 2) + game->dir_y * cos(PI / 2));
    while (i < 60)
    {
        my_mlx_pixel_put(game->img, x0 + xdir * i, y0 + ydir * i, 0x0000FF00);
        i++;
    }
    xdir = (game->dir_x * cos(-PI / 2) - game->dir_y * sin(-PI / 2));
    ydir = (game->dir_x * sin(-PI / 2) + game->dir_y * cos(-PI / 2));
    i = 0;
    while (i < 60)
    {
        my_mlx_pixel_put(game->img, x0 + xdir * i, y0 + ydir * i, 0x0000FF00);
        i++;
    }
}
