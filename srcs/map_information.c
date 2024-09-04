/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_information.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:18:59 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/04 17:47:47 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void    get_player_initial_position(t_game *game)
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
            if (game->map->map[i][j] == 'N' ||game->map->map[i][j] == 'S' \
                || game->map->map[i][j] == 'E' || game->map->map[i][j] == 'W')
            {
                game->pos_x = (double)j;
                game->pos_y = (double)i;
                game->pos_x += 0.5;
                game->pos_y += 0.5;
                return ;
            }
            j++;
        }
        i++;
    }
}
