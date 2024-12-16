/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:24:17 by rolamber          #+#    #+#             */
/*   Updated: 2024/12/13 18:07:53 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		check_arg(int ac, char **av);
void	set_map_pars(t_map_pars *map_pars);
void	set_keys(t_keys *keys);
void	set_img(t_my_img *img);

static	void	set_game_struct(t_game *game, t_keys *keys,
	t_map_pars *map_pars)
{
	game->keys = keys;
	game->map_pars = map_pars;
	game->mouse_x = 0;
	game->map = NULL;
	game->img = NULL;
	game->win_ptr = NULL;
	game->mlx_ptr = NULL;
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
	set_keys(game->keys);
	set_map_pars(game->map_pars);
}

static	int	init_mlx(t_game *game)
{
	t_my_img	*img;

	img = NULL;
	img = malloc(sizeof(t_my_img));
	if (!img)
		return (0);
	game->img = img;
	set_img(game->img);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (0);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	if (!game->win_ptr)
		return (0);
	img->ptr = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img->ptr)
		return (0);
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	if (!img->addr)
		return (0);
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
	t_game			game;
	t_keys			keys;
	t_map_pars		map_pars;

	if (check_arg(ac, av))
		return (1);
	set_game_struct(&game, &keys, &map_pars);
	if (parsing(av[1], &game) == -1)
	{
		free_all(&game);
		return (printf("Error\nParsing failed\n"), 1);
	}
	if (!init_mlx(&game))
	{
		free_all(&game);
		return (printf("Error\nMlx failed\n"), 1);
	}
	if (load_textures(&game) == -1)
	{
		free_all(&game);
		return (printf("Error\nLoading textures failed\n"), 1);
	}
	game_loop(&game);
	return (0);
}
