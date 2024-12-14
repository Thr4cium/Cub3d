/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_routine_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:17:12 by rolamber          #+#    #+#             */
/*   Updated: 2024/12/03 15:29:30 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	check_map_information(t_map *map)
{
	char	**tmp;
	int		i;
	int		j;

	if (!map->map)
		return (printf("Error\n no map information\n"), -1);
	tmp = map->map;
	j = 0;
	i = 0;
	while (tmp[i])
	{
		if (ft_strsearch(tmp[i], 'N') == 1 || ft_strsearch(tmp[i], 'S') == 1 \
			|| ft_strsearch(tmp[i], 'W') == 1 || ft_strsearch(tmp[i], 'E') == 1)
			j++;
		if (j > 1)
			return (printf("Error\n too many player starting points\n"), -1);
		if (!is_line_only_map(tmp[i]))
			return (printf("Error\n wrong map information\n"), -1);
		i++;
	}
	if (check_map_validity(map) == -1 || check_map_validity_bis(map) == -1)
		return (-1);
	return (0);
}

int	check_map_validity(t_map *map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (map->map[++i])
	{
		j = 0;
		while (map->map[i][j++])
		{
			if ((j == 0 || j == ft_strlen(map->map[i]) - 1) \
				&& map->map[i][j] == '0')
				return (printf("Error\n map is not closed\n"), -1);
			else if (map->map[i][j] == '0')
			{
				if (i == 0 || i == map->map_y - 1)
					return (printf("Error\n map is not closed\n"), -1);
				if (map->map[i][j + 1] == ' ' || map->map[i][j - 1] == ' ' \
					|| ft_strlen(map->map[i + 1]) - 1 < j
					|| ft_strlen(map->map[i - 1]) - 1 < j
					|| map->map[i + 1][j] == ' ' || map->map[i - 1][j] == ' ')
					return (printf("Error\n map is not closed\n"), -1);
			}
		}
	}
	return (0);
}

int	check_map_validity_bis(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (case_first_last_line(map) == -1)
		return (printf("Error\n map is not closed\n"), -1);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (i != ft_strlen(map->map[i]) - 1 && i != 0)
			{
				if (map->map[i][j] == '0' && ft_strlen(map->map[i - 1]) <= j)
					return (printf("Error\n map is not closed\n"), -1);
				if (map->map[i][j] == '0' && ft_strlen(map->map[i + 1]) <= j)
					return (printf("Error\n map is not closed\n"), -1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	case_first_last_line(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[0][i])
	{
		if (map->map[0][i] == '0' && ft_strlen(map->map[1]) <= i)
			return (-1);
		i++;
	}
	i = 0;
	while (map->map[map->map_y - 1][i])
	{
		if (map->map[map->map_y - 1][i] == '0' \
			&& ft_strlen(map->map[map->map_y - 2]) <= i)
			return (-1);
		i++;
	}
	return (0);
}

int	check_path(char *path)
{
	int	fd;

	if (ft_strnstr(&path[ft_strlen(path) - 4], ".cub", 4) == NULL)
		return (printf("Error\n wrong file extension\n"), -1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror("open"), -1);
	close(fd);
	return (0);
}
