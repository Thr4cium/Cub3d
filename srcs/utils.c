/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:18:17 by rolamber          #+#    #+#             */
/*   Updated: 2024/12/02 14:34:51 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

char	*ft_strdup_trim(char *line)
{
	char	*trimmed_line;
	char	*ret;

	trimmed_line = ft_strtrim(line, "\n");
	if (!trimmed_line)
		return (NULL);
	ret = ft_strdup(trimmed_line);
	free(trimmed_line);
	return (ret);
}

void	free_textures(t_game *game)
{
	if (game->no_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->no_img->ptr);
		free(game->no_img);
	}
	if (game->so_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->so_img->ptr);
		free(game->so_img);
	}
	if (game->we_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->we_img->ptr);
		free(game->we_img);
	}
	if (game->ea_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->ea_img->ptr);
		free(game->ea_img);
	}
}

void	free_all(t_game *game)
{
	int	i;

	free_textures(game);
	i = 0;
	if (game->map->map)
	{
		while (game->map->map[i])
		{
			free(game->map->map[i]);
			i++;
		}
	}
	if (game->map->map)
		free(game->map->map);
	if (game->map->no_texture)
		free(game->map->no_texture);
	if (game->map->so_texture)
		free(game->map->so_texture);
	if (game->map->we_texture)
		free(game->map->we_texture);
	if (game->map->ea_texture)
		free(game->map->ea_texture);
	if (game->map)
		free(game->map);
}

int	end_game(t_game *game)
{
	free_all(game);
	mlx_destroy_image(game->mlx_ptr, game->img->ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	if (game->img)
		free(game->img);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
	exit(0);
}

void	my_mlx_pixel_put(t_my_img *img, int x, int y, int color)
{
	char	*dst;

	if (!img || !img->addr)
	return ;
	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
