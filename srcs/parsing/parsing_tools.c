/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:02:43 by rolamber          #+#    #+#             */
/*   Updated: 2024/12/16 21:45:40 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->res_x = -1;
	map->res_y = -1;
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->we_texture = NULL;
	map->ea_texture = NULL;
	map->ground_color = -1;
	map->sky_color = -1;
	map->map = NULL;
	map->map_x = 0;
	map->map_y = 0;
	return (map);
}

bool	are_texture_filled(t_map *map)
{
	if (!map->no_texture || !map->so_texture \
		|| !map->we_texture || !map->ea_texture \
		|| map->ground_color == -1 || map->sky_color == -1)
	{
		return (false);
	}
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
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != 'E' \
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W' \
				&& line[i] != '0')
			return (false);
		i++;
	}
	return (true);
}

bool	is_line_only_map(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '1' && *line != '0' && *line != 'N' \
			&& *line != 'S' && *line != 'W' && *line != 'E')
			return (false);
		line++;
	}
	return (true);
}
