/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:35:56 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/03 16:38:03 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	my_mlx_pixel_put(t_my_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int secure_my_mlx_pixel_put(t_my_img *img, int x, int y, int color)
{
    if (x >= 0 && x > SCREEN_WIDTH / 3 && x < ((SCREEN_WIDTH * 2 )/ 3) && y >= 0 && y > SCREEN_HEIGHT / 3)
    { 
        my_mlx_pixel_put(img, x, y, color);
        return (0);
    }
    return ( -1);
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
                my_mlx_pixel_put(game->img, x + x1, y + y1, color);
                x1++;
            }
        else
            while (x1 > 0)
            {
                my_mlx_pixel_put(game->img, x + x1, y + y1, color);
                x1--;
            }
        i += 0.1;
    }
}

void    print_player(t_game *game, int x, int y, int r)
{
    draw_round(game, x, y, r, 0x00FF0000);
}