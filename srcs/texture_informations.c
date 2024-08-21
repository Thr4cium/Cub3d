/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_informations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:01:09 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/21 15:36:31 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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

int	rgb_to_int(char *line)
{
	int		i;
	int		j;
	char	color[4] = {0};
	int		rgb;

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
