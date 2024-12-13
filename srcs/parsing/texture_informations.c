/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_informations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:01:09 by rolamber          #+#    #+#             */
/*   Updated: 2024/12/13 17:22:11 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	get_texture_information(t_map *map, char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strncmp(array[i], "NO ", 3) == 0)
			map->no_texture = ft_strdup_trim(array[i] + 3);
		else if (ft_strncmp(array[i], "SO ", 3) == 0)
			map->so_texture = ft_strdup_trim(array[i] + 3);
		else if (ft_strncmp(array[i], "WE ", 3) == 0)
			map->we_texture = ft_strdup_trim(array[i] + 3);
		else if (ft_strncmp(array[i], "EA ", 3) == 0)
			map->ea_texture = ft_strdup_trim(array[i] + 3);
		else if (ft_strncmp(array[i], "C ", 2) == 0)
			map->sky_color = rgb_to_int(array[i] + 1);
		else if (ft_strncmp(array[i], "F ", 2) == 0)
			map->ground_color = rgb_to_int(array[i] + 1);
		else if (!is_line_only_empty(array[i]) && !is_line_is_map(array[i]))
			return (free_array(array),
				printf("Error\n Wrong texture information\n"), -1);
		if (are_texture_filled(map))
			return (i);
		i++;
	}
	return (printf("Error\n no texture informations found\n"), -1);
}

int	check_texture_information(t_map *map)
{
	int	fd;

	fd = open(map->no_texture, O_RDONLY);
	if (fd == -1)
		return (perror(map->no_texture), -1);
	close(fd);
	fd = open(map->so_texture, O_RDONLY);
	if (fd == -1)
		return (perror(map->so_texture), -1);
	close(fd);
	fd = open(map->we_texture, O_RDONLY);
	if (fd == -1)
		return (perror(map->we_texture), -1);
	close(fd);
	fd = open(map->ea_texture, O_RDONLY);
	if (fd == -1)
		return (perror(map->ea_texture), -1);
	close(fd);
	if (check_color_information(map) == -1)
		return (-1);
	return (0);
}

int	check_color_information(t_map *map)
{
	if (map->ground_color < 0 || map->sky_color < 0)
		return (printf("Error\n wrong color information\n"), -1);
	return (0);
}

int	rgb_to_int(char *line)
{
	int		i;
	int		j;
	int		rgb;
	char	color[4];

	while (*line == ' ')
		line++;
	ft_bzero(color, 4);
	i = 0;
	j = 0;
	rgb = 0;
	while (*line && j < 3)
	{
		while (*line != ',' && *line != '\n' && i < 3)
		{
			if (!ft_isdigit(*line))
				return (printf("Error\n wrong color information\n"), -1);
			color[i++] = *line++;
		}
		rgb = rgb_to_int_tool(j++, color, rgb);
		ft_bzero(color, 4);
		i = 0;
		line++;
	}
	return (rgb);
}

int	rgb_to_int_tool(int j, char *color, int rgb)
{
	if (!color)
		return (printf("Error\n wrong color information\n"), -1);
	if (j == 0)
		rgb = ft_atoi(color) << 16;
	else if (j == 1)
		rgb += ft_atoi(color) << 8;
	else if (j == 2)
		rgb += ft_atoi(color);
	return (rgb);
}
