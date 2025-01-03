/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_informations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:01:09 by rolamber          #+#    #+#             */
/*   Updated: 2024/12/19 17:50:54 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	assign_variables(size_t *i, size_t *j, int *rgb);
char	*trim_space(char *line);
bool	check_rgb(char *line);

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
		if (are_texture_filled(map))
			return (i);
		i++;
	}
	return (printf("Error\nno texture informations found\n"), -1);
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
		return (printf("Error\nwrong color information\n"), -1);
	return (0);
}

int	rgb_to_int(char *line)
{
	size_t		i;
	size_t		j;
	int			rgb;
	char		color[4];

	line++;
	ft_bzero(color, 4);
	assign_variables(&i, &j, &rgb);
	if (!check_rgb(line))
		return (printf("Error\nwrong color information\n"), -1);
	while (*line && j < 3)
	{
		while (*line && *line != ',' && *line != '\n' && i < 3)
			color[i++] = *line++;
		if (*line == '\0')
			break ;
		rgb = rgb_to_int_tool(j++, color, rgb);
		ft_bzero(color, 4);
		i = 0;
		if (*line == ',' || *line == '\n')
			line++;
	}
	return (rgb);
}

int	rgb_to_int_tool(int j, char *color, int rgb)
{
	if (!color)
		return (printf("Error\nwrong color information\n"), -1);
	if (j == 0)
		rgb = ft_atoi(color) << 16;
	else if (j == 1)
		rgb += ft_atoi(color) << 8;
	else if (j == 2)
		rgb += ft_atoi(color);
	return (rgb);
}
