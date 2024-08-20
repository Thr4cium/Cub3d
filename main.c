/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:24:17 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/20 16:18:46 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

void    init_game_struct(t_game *game)
{
    game->map = NULL;
}

int main(char **av, int ac)
{
    t_game	game;

    if (ac != 2)
        return (printf("Error\nInvalid number of arguments\n"), 1);
    init_game_struct(&game);
    if (parsing(av[1], &game) == -1)
    {
        free_all(&game);
        return (1, printf("Error\nParsing failed\n"));
    }
    return (0);
}
