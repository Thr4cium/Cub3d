/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:42:22 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/20 15:45:39 by rolamber         ###   ########.fr       */
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
}

int	get_texture_information(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO", 2))
			map->no_texture = ft_strdup(line + 2);
		else if (ft_strncmp(line, "SO", 2))
			map->so_texture = ft_strdup(line + 2);
		else if (ft_strncmp(line, "WE", 2))
			map->we_texture = ft_strdup(line + 2);
		else if (ft_strncmp(line, "EA", 2))
			map->ea_texture = ft_strdup(line + 2);
		else if (ft_strncmp(line, "C" , 2))
			map->sky_color = rgb_to_int(line);
		else if (ft_strncmp(line, "F ", 2))
			map->ground_color = rgb_to_int(line);
		else if (!is_line_only_empty(line) && !is_line_is_map(line))
			return (free(line), printf("Error : wrong texture information\n"), -1);
		if (are_texture_filled(map))
			return (free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	return (printf("Error : no texture informations found\n"), -1);
}

int	get_map_information(t_map *map, int fd)
{
	char	*line;
	char 	*trimmed_line;

	line = get_next_line(fd);

	while (line)
	{
		trimmed_line = ft_strtrim(line, "\n");
		map->map = ft_realloc	
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	
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
	map->ground_color = 0;
	map->sky_color = 0;
	map->map = NULL;
	map->map_x = 0;
	map->map_y = 0;
}

int	check_texture_information(t_map *map)
{
	int fd;

	fd = open(map->no_texture, O_RDONLY);
	if (fd == -1)
		return (perror("open"), -1);
	close(fd);
	fd = open(map->so_texture, O_RDONLY);
	if (fd == -1)
		return (perror("open"), -1);
	close(fd);
	fd = open(map->we_texture, O_RDONLY);
	if (fd == -1)
		return (perror("open"), -1);
	close(fd);
	fd = open(map->ea_texture, O_RDONLY);
	if (fd == -1)
		return (perror("open"), -1);
	close(fd);
	if (check_color_information(map) == -1)
		return (-1);
	return (0);
}

int	check_color_information(t_map *map)
{
	if (map->ground_color < 0 || map->sky_color < 0)
		return (printf("Error : wrong color information\n"), -1);	
	return (0);
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
	if (!map->no_texture || !map->so_texture || !map->we_texture || !map->ea_texture \
			|| map->ground_color == 0 || map->sky_color == 0)
		return (false);
	return (true);
}

bool	is_line_only_empty(char *line)
{
	if (line[0] != '\n')
		return (false);
	return (true);
}

bool	is_line_is_map(char *line)
{
	if (strchr(line, '0') || strchr(line, '1') || strchr(line, 'N') \
		|| strchr(line, 'S') || strchr(line, 'W') || strchr(line, 'E'))
		return (true);
	return (false);
}

int	rgb_to_int(char *line)
{
	char color[4] = {0};
	int rgb;
	int i;
	int j;

	while (*line == ' ')
		line++;
	i = 0;
	j = 0;
	rgb = 0;
	while (*line && j < 3)
	{
		while (*line != ',' && i  < 3)
		{
			if (!ft_isdigit(*line))
				return (printf("Error : wrong color information\n"), -1);	
			color[i++] = *line;
		}
		rgb = rgb_to_int_tool(j, color, rgb);
		ft_bzero(color, 4);
		i = 0;
		j++;
		line++;
	}
	return (rgb);
}

int rgb_to_int_tool(int j, char *color, int rgb)
{
	if (!color)
		return (printf("Error : wrong color information\n"), -1);
	if (j == 0)
		rgb = ft_atoi(color) << 16;
	else if (j == 1)
		rgb += ft_atoi(color) << 8;
	else if (j == 2)
		rgb += ft_atoi(color);
	return (rgb);
}
