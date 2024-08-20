/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:42:22 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/20 16:08:58 by rolamber         ###   ########.fr       */
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
	if (check_texture_information(map) == -1)
		return (-1);
	if (get_map_information(map, fd) == -1)
		return (-1);
	if (check_map_information(map) == -1)\
		return (-1);
	
}

int	get_map_information(t_map *map, int fd)
{
	char	*line;
	char 	*trimmed_line;

	line = get_next_line(fd);

	while (line)
	{
		trimmed_line = ft_strtrim(line, "\n");
		if (!trimmed_line)
			return (perror("malloc"), -1);
		map->map = map_addline(map->map, trimmed_line);
		if (!map->map)
			return (perror("malloc"), -1);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}

char **map_addline(char **map, char *line)
{
	int i;
	char **new_map;

	i = 0;
	if (map)
		while (map[i])
			i++;
	new_map = ft_calloc(sizeof(char *) , i + 2);
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
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
