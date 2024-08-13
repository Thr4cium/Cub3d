/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:42:22 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/13 12:07:05 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

int	parsing(char *path, t_game *game)
{

	game->map = init_map();
	if (!game->map)
		return (-1);
	if (get_information(path, game->map) == -1)
		return (-1);
}

int get_information(char *path, t_map *map)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror("open"), -1);
	if (get_texture_information(map, fd) == -1)
		return (-1);
}

int	get_texture_information(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO", 2))
			map->no_texture = ft_strdup(line + 3);
		else if (ft_strncmp(line, "SO", 2))
			map->so_texture = ft_strdup(line + 3);
		else if (ft_strncmp(line, "WE", 2))
			map->we_texture = ft_strdup(line + 3);
		else if (ft_strncmp(line, "EA", 2))
			map->ea_texture = ft_strdup(line + 3);
		else if (ft_strncmp(line, "S", 1))
			map->s_texture = ft_strdup(line + 2);
		else if (!is_line_only_empty(line))
			return (printf("wrong texture information\n"), -1);
		if (are_texture_filled(map))
			return (0);
		line = get_next_line(fd);
	}
}

int	get_map_information(t_map *map)
{

}

t_map   *init_map(void)
{
	t_map    *map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->res_x = -1;
	map->res_y = -1;
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->we_texture = NULL;
	map->ea_texture = NULL;
	map->s_texture = NULL;
	map->map = NULL;
	map->map_x = 0;
	map->map_y = 0;
}

int	check_texture_information(t_map *map)
{

}

int	check_map_information(t_map *map)
{

}

int	check_path(char *path)
{

}

free_all(t_game *game)
{
	free(game->map);
	
}

bool are_texture_filled(t_map *map)
{
	if (!map->no_texture || !map->so_texture || !map->we_texture || !map->ea_texture || !map->s_texture)
		return (false);
	return (true);
}