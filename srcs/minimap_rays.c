/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:39:59 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/05 17:04:27 by rolamber         ###   ########.fr       */
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

void    ray_casting(t_game *game)
{
    int i;
    double Vdir_x;
    double Vdir_y;
    double angle_increment = (PI / 2) / SCREEN_WIDTH;

    i = 0;
    Vdir_x = (game->dir_x * cos(-PI / 2) - game->dir_y * sin(-PI / 2));
    Vdir_y = (game->dir_x * sin(-PI / 2) + game->dir_y * cos(-PI / 2));
    while (i < SCREEN_WIDTH)
    {
        Vdir_x = (game->dir_x * cos(angle_increment * i) - game->dir_y * sin(angle_increment * i));
        Vdir_y = (game->dir_x * sin(angle_increment * i) + game->dir_y * cos(angle_increment * i));
        if (ray_cast(game, Vdir_x, Vdir_y) == -1)
            return ;
        i++;
    }
}

int ray_cast(t_game *game, double Vdir_x, double Vdir_y)
{
    t_ray ray;

    ray = calloc(1, sizeof(t_ray));
    if (ray == NULL)
        return -1;
    init_ray(game, ray, Vdir_x, Vdir_y);
    return (0);
}

void    init_ray(t_game *game, t_ray ray, double Vdir_x, double Vdir_y)
{
    ray.mapX = (int)game->pos_x;
    ray.mapY = (int)game->pos_y;
    if (Vdir_x == 0)
        ray.deltaDistX = 1e30;
    else
        ray.deltaDistX = fabs(1 / Vdir_x);
    if (Vdir_y == 0)
        ray.deltaDistY = 1e30;
    else
        ray.deltaDistY = fabs(1 / Vdir_y);
    init_ray2(game, ray, Vdir_x, Vdir_y);
  
}

void    init_ray2(t_game *game, t_ray ray, double Vdir_x, double Vdir_y)
{
    if (Vdir_x < 0)
    {
        ray.stepX = -1;
        ray.sideDistX = (game->pos_x - ray.mapX) * ray.deltaDistX;
    }
    else
    {
        ray.stepX = 1;
        ray.sideDistX = (ray.mapX + 1.0 - posX) * ray.deltaDistX;
    }
    if (Vdir_y < 0)
    {
        ray.stepY = -1;
        ray.sideDistY = (game->pos_y - ray.mapY) * ray.deltaDistY;
    }
    else
    {
        ray.stepY = 1;
        ray.sideDistY = (ray.mapY + 1.0 - game->pos_y) * ray.deltaDistY;
    }
}
