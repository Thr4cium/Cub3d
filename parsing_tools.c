/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:02:43 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/20 16:03:43 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

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
