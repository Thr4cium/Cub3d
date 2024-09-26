/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:42:22 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/26 09:45:31 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	actualise_map(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	max;

	i = 0;
	max = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	map->map_y = i;
	map->map_x = max;
}

int	parsing(char *path, t_game *game)
{
	game->map = init_map();
	if (!game->map)
		return (-1);
	if (get_information(path, game->map) == -1)
		return (-1);
	get_player_initial_position(game);
	game->tile_size = SCREEN_WIDTH / game->map->map_x;
	init_vectors(game);
	return (0);
}

int	get_information(char *path, t_map *map)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror("open"), -1);
	if (get_texture_information(map, fd) == -1)
		return (-1);
	if (check_texture_information(map) == -1)
		return (-1);
	if (get_map_information(map, fd) == -1)
		return (-1);
	if (check_map_information(map) == -1)
		return (-1);
	return (0);
}

int	get_map_information(t_map *map, int fd)
{
	char	*line;
	char	*trimmed_line;

	line = get_next_line(fd);
	while (line)
	{
		while (is_line_only_empty(line))
		{
			free(line);
			line = get_next_line(fd);
		}
		printf("here %s\n", line);
		trimmed_line = ft_strtrim(line, "\n");
		if (!trimmed_line)
			return (perror("malloc"), -1);
		map->map = map_addline(map->map, trimmed_line);
		free(line);
		if (!map->map)
			return (perror("malloc"), -1);
		line = get_next_line(fd);
	}
	free(line);
	actualise_map(map);
	return (0);
}

char	**map_addline(char **map, char *line)
{
	int		i;
	char	**new_map;

	printf("line : %s\n", line);
	i = 0;
	if (map)
		while (map[i])
			i++;
	new_map = ft_calloc(sizeof(char *), i + 2);
	if (!new_map)
		return (NULL);
	i = 0;
	if (map)
	{
		while (map[i])
		{
			new_map[i] = map[i];
			i++;
		}
	}
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}
