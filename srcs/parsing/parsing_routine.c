/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:42:22 by rolamber          #+#    #+#             */
/*   Updated: 2024/12/13 16:59:52 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

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
	return (0);
}

int	get_information(char *path, t_map *map)
{
	int		fd;
	int		i;
	char	**array;

	array = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror("open"), -1);
	array = copy_file(fd);
	close(fd);
	if (!array)
		return (perror("malloc"), -1);
	if (check_edge_cases(array) == -1)
		return (-1);
	i = get_texture_information(map, array);
	if (i == -1)
		return (-1);
	if (check_texture_information(map) == -1)
		return (free_array(array), -1);
	if (get_map_information(map, array, i) == -1)
		return (free_array(array), -1);
	if (check_map_information(map) == -1)
		return (-1);
	return (0);
}

int	get_map_information(t_map *map, char **array, int i)
{
	char	*trimmed_line;

	i++;
	while (array[i])
	{
		while (is_line_only_empty(array[i]))
			i++;
		trimmed_line = ft_strtrim(array[i], "\n");
		if (!trimmed_line)
			return (perror("malloc"), -1);
		map->map = map_addline(map->map, trimmed_line);
		if (!map->map)
			return (perror("malloc"), -1);
		i++;
	}
	free_array(array);
	actualise_map(map);
	return (0);
}

char	**map_addline(char **map, char *line)
{
	int		i;
	char	**new_map;

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
			new_map[i] = ft_strdup(map[i]);
			i++;
		}
	}
	new_map[i] = ft_strdup(line);
	new_map[i + 1] = NULL;
	free_array(map);
	return (new_map);
}
