/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:42:22 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/21 15:29:21 by rolamber         ###   ########.fr       */
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
	return (0);
}

int	get_map_information(t_map *map, int fd)
{
	char	*line;
	char 	*trimmed_line;

	line = get_next_line(fd);

	while (line)
	{
		while (is_line_empty(line))
		{
			free(line);
			line = get_next_line(fd);
		}
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
	char **tmp;
	int i;
	int j;

	if (!map->map)
		return (printf("Error : no map information\n"), -1);
	tmp = map->map;
	j = 0;
	i = 0;
	while (tmp[i])
	{
		if  (ft_strsearch(tmp[i], 'N') == 1 || ft_strsearch(tmp[i], 'S') == 1 \
			|| ft_strsearch(tmp[i], 'W') == 1 || ft_strsearch(tmp[i], 'E') == 1)
			j++;
		if (j > 1)
			return (printf("Error : too many player starting points\n"), -1);
		if (!is_line_only_map(tmp))
			return (printf("Error : wrong map information\n"), -1);
		i++;
	}
	if (check_map_validity(map) == -1)
		return (-1);
	return (0);
}

int	check_map_validity(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0')
			{
				if (map->map[i][j + 1] == ' ' || map->map[i][j - 1] == ' ' \
					|| map->map[i + 1][j] == ' ' || map->map[i - 1][j] == ' ')
					return (printf("Error : map is not closed\n"), -1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_path(char *path)
{
	int fd;

	if (ft_strsearch(&path[ft_strlen(path) - 3], ".cub") == 0)
		return (printf("Error : wrong file extension\n"), -1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror("open"), -1);
	close(fd);
	return (0);
}

void	free_all(t_game *game)
{
	int i;

	i = 0;
	while (game->map->map[i])
	{
		free(game->map->map[i]);
		i++;
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
