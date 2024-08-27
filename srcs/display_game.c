/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:06:33 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/27 16:27:18 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int display_game(t_game *game)
{
    print_minimap(game);
    print_player(game);
    print_rays(game);
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

void    print_player(t_game *game)
{
    mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->pos_x, game->pos_y, 0x00FF0000);
}

