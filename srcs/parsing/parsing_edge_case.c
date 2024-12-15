/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_edge_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:44:08 by rolamber          #+#    #+#             */
/*   Updated: 2024/12/03 15:35:53 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array != NULL)
	{
		while (array[i] != NULL)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

int	check_textures_keys(char *line, char *str, int n, t_map_pars *m_pars)
{
	if (ft_strncmp(line, str, n) == 0)
	{
		if (ft_strcmp(str, "NO ") == 0)
			m_pars->no++;
		else if (ft_strcmp(str, "SO ") == 0)
			m_pars->so++;
		else if (ft_strcmp(str, "WE ") == 0)
			m_pars->we++;
		else if (ft_strcmp(str, "EA ") == 0)
			m_pars->ea++;
		else if (ft_strcmp(str, "C ") == 0)
			m_pars->c++;
		else if (ft_strcmp(str, "F ") == 0)
			m_pars->f++;
	}
	if (m_pars->no > 1 || m_pars->so > 1 || m_pars->we > 1
		|| m_pars->ea > 1 || m_pars->c > 1 || m_pars->f > 1)
		return (printf("Error\n double keys detected\n"), -1);
	return (0);
}

int	check_edge_cases(char **array, t_map_pars *m_pars)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (check_textures_keys(array[i], "NO ", 3, m_pars) == -1)
			return (free_array(array), -1);
		else if (check_textures_keys(array[i], "SO ", 3, m_pars) == -1)
			return (free_array(array), -1);
		else if (check_textures_keys(array[i], "WE ", 3, m_pars) == -1)
			return (free_array(array), -1);
		else if (check_textures_keys(array[i], "EA ", 3, m_pars) == -1)
			return (free_array(array), -1);
		else if (check_textures_keys(array[i], "C ", 2, m_pars) == -1)
			return (free_array(array), -1);
		else if (check_textures_keys(array[i], "F ", 2, m_pars) == -1)
			return (free_array(array), -1);
		if (is_line_is_map(array[i]))
			return (0);
		i++;
	}
	return (0);
}

char	**copy_file(int fd)
{
	char	*line;
	char	**array;
	char	**tmp;

	array = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tmp = map_addline(array, line);
		free(line);
		if (!tmp)
		{
			free_array(array);
			return (NULL);
		}
		array = tmp;
		line = get_next_line(fd);
	}
	return (array);
}
