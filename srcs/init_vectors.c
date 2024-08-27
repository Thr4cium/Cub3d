/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vectors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:41:39 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/27 16:34:12 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void    init_vectors(t_game *game)
{
    init_dir_vectors(game);
}

void    init_dir_vectors(t_game *game)
{
    char **temp;
    int i;
    int j;

    temp = game->map->map;
    i = 0;
    j = 0;
    while (temp[i])
    {
        while(temp[i][j])
        {
            if (temp[i][j] == 'N' || temp[i][j] == 'S')
                game->dir_x = 0;               
            if (temp [i][j] == 'E')
                game->dir_x = 1;
            if (temp [i][j] == 'W')
                game->dir_x = -1;
            j++;
        }
    }
}
