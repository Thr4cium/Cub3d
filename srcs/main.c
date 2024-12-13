/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:24:17 by rolamber          #+#    #+#             */
/*   Updated: 2024/12/02 11:42:01 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static	void	set_game_struct(t_game *game, t_keys *keys)
{
	game->keys = keys;
	game->mouse_x = 0;
	game->map = NULL;
	game->pos_x = 0;
	game->pos_y = 0;
	game->dir_x = 0;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66;
	game->so_img = NULL;
	game->no_img = NULL;
	game->ea_img = NULL;
	game->we_img = NULL;
	game->keys->esc = false;
	game->keys->w = false;
	game->keys->s = false;
	game->keys->a = false;
	game->keys->d = false;
	game->keys->left = false;
	game->keys->right = false;
	game->keys->is_pristine = true;
}

static	int	init_mlx(t_game *game)
{
	t_my_img	*img;

	img = malloc(sizeof(t_my_img));
	if (!img)
		return (0);
	game->img = img;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
		SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	img->ptr = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	return (1);
}

void	game_loop(t_game *game)
{
	mlx_hook(game->win_ptr, MLX_CROSS_CODE, 0, &end_game, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask,
		&handle_keyrelease, game);
	mlx_loop_hook(game->mlx_ptr, &update_game, game);
	mlx_loop(game->mlx_ptr);
}

void	print_map_info(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->map[i])
	{
		printf("%s\n", game->map->map[i]);
		i++;
	}
	printf("g color : %d\n", game->map->ground_color);
	printf("s color : %d\n", game->map->sky_color);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_keys	keys;

	if (ac != 2)
		return (printf("Error\nInvalid number of arguments\n"), 1);
	if (check_path(av[1]) == -1)
		return (printf("Error\nInvalid path\n"), 1);
	set_game_struct(&game, &keys);
	if (parsing(av[1], &game) == -1)
	{
		free_all(&game);
		return (printf("Error\nParsing failed\n"), 1);
	}
	init_mlx(&game);
	if (load_textures(&game) == -1)
	{
		free_all(&game);
		return (printf("Error\nLoading textures failed\n"), 1);
	}
	game_loop(&game);
	free_all(&game);
	return (0);
}
