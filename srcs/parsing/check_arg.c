/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:48:21 by magrondi          #+#    #+#             */
/*   Updated: 2024/12/19 15:06:30 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	check_arg(int ac, char **av)
{
	if (ac != 2 && ac != 3)
		return (printf("Error\nwrong number of arguments\n"), -1);
	if (ac == 3 && ft_strncmp(av[2], "--save", 7) != 0)
		return (printf("Error\nwrong argument\n"), -1);
	if (check_path(av[1]) == -1)
		return (-1);
	return (0);
}

static	bool	has_reach_max_width(int i, char **gnl_reuslt)
{
	if (ft_strlen(gnl_reuslt[i]) > FILE_MAX_WIDTH)
	{
		printf("Error\nfile width need to be less then ");
		printf("%d\n", FILE_MAX_WIDTH);
		free_array(gnl_reuslt);
		return (true);
	}
	return (false);
}

static	bool	has_reach_max_height(int i, char **gnl_reuslt)
{
	if (i > FILE_MAX_HEIGHT)
	{
		printf("Error\nfile height need to be less then ");
		printf("%d\n", FILE_MAX_HEIGHT);
		free_array(gnl_reuslt);
		return (true);
	}
	return (false);
}

char	**check_file_w_h(char **gnl_reuslt)
{
	int	i;
	int	j;

	if (!gnl_reuslt)
		return (NULL);
	i = 0;
	while (gnl_reuslt[i])
	{
		j = 0;
		if (has_reach_max_height(i, gnl_reuslt))
			return (NULL);
		while (gnl_reuslt[i][j])
		{
			if (has_reach_max_width(i, gnl_reuslt))
				return (NULL);
			j++;
		}
		i++;
	}
	return (gnl_reuslt);
}

bool	hole_next_to_player(t_game *game)
{
	char	**map;
	int		p_x;
	int		p_y;

	map = game->map->map;
	p_x = game->pos_x;
	p_y = game->pos_y;
	if (map[p_y][p_x - 1] != '1' && map[p_y][p_x - 1] != '0')
		return (printf("Error\nInvalid element to the left of the player\n"),
			true);
	if (map[p_y - 1][p_x] != '1' && map[p_y - 1][p_x] != '0')
		return (printf("Error\nInvalid element above the player\n"), true);
	if (map[p_y][p_x + 1] != '1' && map[p_y][p_x + 1] != '0')
		return (printf("Error\nInvalid element to the right of the player\n"),
			true);
	if (p_y + 1 >= (int) game->map->map_y)
		return (printf("Error\nInvalid element below the player\n"), true);
	if (map[p_y + 1][p_x] != '1' && map[p_y + 1][p_x] != '0')
		return (printf("Error\nInvalid element below the player\n"), true);
	return (false);
}
