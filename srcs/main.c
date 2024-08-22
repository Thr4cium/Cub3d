/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:24:17 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/22 17:33:27 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void    init_game_struct(t_game *game)
{
    game->map = NULL;
}

void print_map_info(t_game *game)
{
    int i = 0;
    while (game->map->map[i])
    {
        printf("%s\n", game->map->map[i]);
        i++;
    }
    printf("g color : %d\n", game->map->ground_color);
    printf("s color : %d\n", game->map->sky_color);
}

int main(int ac, char **av)
{
    t_game	game;

    if (ac != 2)
        return (printf("Error\nInvalid number of arguments\n"), 1);
    if (check_path(av[1]) == -1)
        return (printf("Error\nInvalid path\n"), 1);
    init_game_struct(&game);
    if (parsing(av[1], &game) == -1)
    {
        free_all(&game);
        return (printf("Error\nParsing failed\n"), 1);
    }
    free_all(&game);
    return (0);
}
