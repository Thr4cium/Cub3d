/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:24:17 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/28 15:19:01 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void    init_game_struct(t_game *game)
{
    game->map = NULL;
    game->pos_x = 0;
    game->pos_y = 0;
    game->dir_x = 0;
    game->dir_y = 0;
    game->plane_x = 0;
    game->plane_y = 0.66;
}

void init_mlx(t_game *game)
{
    game->mlx_ptr = mlx_init();
    game->win_ptr = mlx_new_window(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
}

void game_loop(t_game *game)
{
    mlx_hook(game->win_ptr, 17, 0, &end_game, game);
    mlx_loop_hook(game->mlx_ptr, &display_game, game);
    mlx_loop(game->mlx_ptr);
}

int end_game(t_game *game)
{
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    mlx_destroy_display(game->mlx_ptr);
    free_all(game);
    exit(0);
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
    init_mlx(&game);
    game_loop(&game);
    free_all(&game);
    return (0);
}
