/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:52:53 by magrondi          #+#    #+#             */
/*   Updated: 2024/12/16 21:45:28 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	assign_variables(int *i, int *j, int *rgb)
{
	*i = 0;
	*j = 0;
	*rgb = 0;
}

char	*trim_space(char *line)
{
	while (*line == ' ')
		line++;
	return (line);
}

static	bool	is_8_bit(char *line)
{
	int		rgb;
	size_t	i;

	i = 0;
	while (line[i])
	{
		rgb = ft_atoi(line + i);
		if (rgb < 0 || rgb > 255)
			return (false);
		while (ft_isdigit(line[i]))
			i ++;
		i ++;
	}
	return (true);
}

static	bool	has_max_3_digits(char *line)
{
	size_t	i;
	size_t	x;
	size_t	comma_count;

	i = 0;
	comma_count = 0;
	while (line && line[i])
	{
		x = 0;
		while (line[i + x] && line[i + x] != ',')
			x ++;
		comma_count++;
		if (x > 3)
			return (false);
		if (comma_count >= 2)
		{
			i += x + 1;
			while (line[i + x] && line[i + x] != '\n')
				x ++;
			if (x > 3)
				return (false);
		}
		i += x + 1;
	}
	return (true);
}

bool	check_rgb(char *line)
{
	size_t	i;
	int		comma_count;

	comma_count = 0;
	i = 0;
	if (!is_8_bit(line) || !has_max_3_digits(line))
		return (false);
	while (line[i])
	{
		if (comma_count >= 2)
		{
			if (!ft_isdigit(line[i]) && line[i] != '\n')
				return (false);
		}
		else
		{
			if (!ft_isdigit(line[i]) && line[i] != ',')
				return (false);
		}
		if (line[i] == ',')
			comma_count++;
		i ++;
	}
	return (true);
}
