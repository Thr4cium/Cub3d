/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:42:22 by rolamber          #+#    #+#             */
/*   Updated: 2024/12/13 18:11:58 by magrondi         ###   ########.fr       */
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

static	int	get_information(char *path, t_map *map, t_map_pars *m_pars)
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
		return (copy_file(-1), perror("malloc"), -1);
	if (check_edge_cases(array, m_pars) == -1)
		return (-1);
	i = get_texture_information(map, array);
	if (i == -1)
		return (-1);
	if (check_texture_information(map) == -1)
		return (free_array(array), -1);
	if (get_map_line_information(map, array, i) == -1)
		return (free_array(array), -1);
	if (check_map_information(map) == -1)
		return (-1);
	return (0);
}

int	parsing(char *path, t_game *game)
{
	game->map = init_map();
	if (!game->map)
		return (-1);
	if (get_information(path, game->map, game->map_pars) == -1)
		return (-1);
	get_player_initial_position(game);
	game->tile_size = SCREEN_WIDTH / game->map->map_x;
	return (0);
}

int	get_map_line_information(t_map *map, char **array, int i)
{
	char	*trimmed_line;

	i++;
	while (array[i])
	{
		while (array[i] && is_line_only_empty(array[i]))
			i++;
		if (!array[i])
			break ;
		trimmed_line = ft_strtrim(array[i], "\n");
		if (!trimmed_line)
			return (perror("malloc"), -1);
		map->map = map_addline(map->map, trimmed_line);
		ft_free(trimmed_line);
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
	while (map && map[i])
		i++;
	new_map = ft_calloc(sizeof(char *), i + 2);
	if (!new_map)
		return (free_array(map), NULL);
	i = 0;
	while (map && map[i])
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = ft_strdup(line);
	if (!new_map[i])
	{
		ft_free(new_map);
		return (free_array(map), NULL);
	}
	new_map[i + 1] = NULL;
	ft_free(map);
	return (new_map);
}
