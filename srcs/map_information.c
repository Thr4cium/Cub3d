/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_information.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:18:59 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/19 05:36:38 by rolamber         ###   ########.fr       */
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

t_texure *create_texture(t_game *game, char *path)
{
    t_texture *texture;

    texture = malloc(sizeof(t_texture));
    if (!texture)
        return (NULL);
    texture->width = 0;
    texture->height = 0;
    texture->bits_per_pixel = 0;
    texture->line_length = 0;
    texture->endian = 0;
    texture->ptr = load_image(path, &texture->width, &texture->height, game);
    if (!texture->ptr)
        return (free(texture), NULL);
    texture->addr = mlx_get_data_addr(texture->ptr, &texture->bits_per_pixel, &texture->line_length, &texture->endian);
    if (!texture->addr)
        return (free(texture), NULL);
    return (texture);
}

int access_texture(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (-1);
    close(fd);
    return (0);
}

void	*load_image(char *path, int *width, int *height, t_game *game)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, width, height);
	if (!ptr)
		end_game(game);
	return (ptr);
}

int load_textures(t_game *game)
{
    if (access_texture(game->map->no_texture) < 0)
        return (-1);
    if (access_texture(game->map->so_texture) < 0)
        return (-1);
    if (access_texture(game->map->we_texture) < 0)
        return (-1);
    if (access_texture(game->map->ea_texture) < 0)
        return (-1);
    game->no_texture = create_texture(game, game->map->no_texture);
    if (!game->no_texture)
        return (perror("malloc no texture failed\n"), -1);
    game->so_texture = create_texture(game, game->map->so_texture);
    if (!game->so_texture)
        return (perror("malloc no texture failed\n"), -1);
    game->we_texture = create_texture(game, game->map->we_texture);
    if (!game->we_texture)
        return (perror("malloc no texture failed\n"), -1);
    game->ea_texture = create_texture(game, game->map->ea_texture);
    if (!game->ea_texture)
        return (perror("malloc no texture failed\n"), -1);
}
