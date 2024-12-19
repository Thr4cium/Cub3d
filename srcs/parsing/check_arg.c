/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:48:21 by magrondi          #+#    #+#             */
/*   Updated: 2024/12/19 15:05:10 by magrondi         ###   ########.fr       */
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
