/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:39:59 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/11 18:26:14 by rolamber         ###   ########.fr       */
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
    ray_casting(game);
}

void    ray_casting(t_game *game)
{
    int i;
    double baseVdir_x;
    double baseVdir_y;
    double Vdir_x;
    double Vdir_y;
    double angle_increment = (PI / 2) / SCREEN_WIDTH;

    i = 0;
    baseVdir_x = (game->dir_x * cos(-PI / 4) - game->dir_y * sin(-PI / 4));
    baseVdir_y = (game->dir_x * sin(-PI / 4) + game->dir_y * cos(-PI / 4));
    while (i < SCREEN_WIDTH)
    {
        Vdir_x = (baseVdir_x * cos(angle_increment * i) - baseVdir_y * sin(angle_increment * i));
        Vdir_y = (baseVdir_x * sin(angle_increment * i) + baseVdir_y * cos(angle_increment * i));
        if (ray_cast(game, Vdir_x, Vdir_y, i) == -1)
            return ;
        i++;
    }
}

int ray_cast(t_game *game, double Vdir_x, double Vdir_y, int i)
{
    t_ray *ray;

    ray = calloc(1, sizeof(t_ray));
    if (ray == NULL)
        return -1;
    init_ray(game, ray, Vdir_x, Vdir_y);
    dda_algorithm(game, ray);
    define_wall_line(game, ray, i, 0x00FFFF00);
    free(ray);
    return (0);
}

void    init_ray(t_game *game, t_ray *ray, double Vdir_x, double Vdir_y)
{
    ray->mapX = (int)game->pos_x;
    ray->mapY = (int)game->pos_y;
    if (Vdir_x == 0)
        ray->deltaDistX = 1e30;
    else
        ray->deltaDistX = fabs(1 / Vdir_x);
    if (Vdir_y == 0)
        ray->deltaDistY = 1e30;
    else
        ray->deltaDistY = fabs(1 / Vdir_y);
    init_ray2(game, ray, Vdir_x, Vdir_y);
}

void    init_ray2(t_game *game, t_ray *ray, double Vdir_x, double Vdir_y)
{
    if (Vdir_x < 0)
    {
        ray->stepX = -1;
        ray->sideDistX = (game->pos_x - ray->mapX) * ray->deltaDistX;
    }
    else
    {
        ray->stepX = 1;
        ray->sideDistX = (ray->mapX + 1.0 - game->pos_x) * ray->deltaDistX;
    }
    if (Vdir_y < 0)
    {
        ray->stepY = -1;
        ray->sideDistY = (game->pos_y - ray->mapY) * ray->deltaDistY;
    }
    else
    {
        ray->stepY = 1;
        ray->sideDistY = (ray->mapY + 1.0 - game->pos_y) * ray->deltaDistY;
    }
}

void    dda_algorithm(t_game *game, t_ray *ray)
{
    bool hit;
    int side;

    side = 0;
    hit = false;
    while (hit == false)
    {
        if (ray->sideDistX < ray->sideDistY)
        {
            ray->sideDistX += ray->deltaDistX;
            ray->mapX += ray->stepX;
            side = 0;
        }
        else
        {
            ray->sideDistY += ray->deltaDistY;
            ray->mapY += ray->stepY;
            side = 1;
        }
        if (game->map->map[ray->mapY][ray->mapX] == '1')
            hit = true;
    }
    ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
    if (side == 0) // axe des X
        ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
}

void    define_wall_line(t_game *game, t_ray *ray, int x, int color)
{
    int lineHeight;
    int drawStart;
    int drawEnd;

    ray->perpWallDist *= (cos(PI / 4 - (x * (PI / 2) / SCREEN_WIDTH)));
    lineHeight = (int)(SCREEN_HEIGHT / ray->perpWallDist);
    drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
    if (drawStart < 0)
        drawStart = 0;
    drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
    if (drawEnd >= SCREEN_HEIGHT)
        drawEnd = SCREEN_HEIGHT - 1;
    while (drawStart < drawEnd)
    {
        secure_my_mlx_pixel_put2(game->img, x, drawStart, color);
        drawStart++;
    }
}