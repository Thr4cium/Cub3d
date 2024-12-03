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

#include "../headers/cub3d.h"

void    free_array(char **array)
{
    int i;

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

int check_textures_keys(char *line, char *str, int n)
{
    static int NO = 0;
    static int SO = 0;
    static int WE = 0;
    static int EA = 0;
    static int C = 0;
    static int F = 0;

    if (ft_strncmp(line, str, n) == 0)
    {
        if (ft_strcmp(str, "NO ") ==  0)
            NO++;
        else if (ft_strcmp(str, "SO ") ==  0)
            SO++;
        else if (ft_strcmp(str, "WE ") ==  0)
            WE++;
        else if (ft_strcmp(str, "EA ") ==  0)
            EA++;
        else if (ft_strcmp(str, "C ") ==  0)
            C++;
        else if (ft_strcmp(str, "F ") == 0)
            F++;
    }
    if (NO > 1 || SO > 1 || WE > 1 || EA > 1 || C > 1 || F > 1)
        return (printf("Error : double keys detected\n"), -1);
    return (0);
}

int check_edge_cases(char **array)
{
    int i;

    i = 0;
	while (array[i])
	{
		if (check_textures_keys(array[i], "NO ", 3) == -1)
            return (free_array(array), -1);
		else if (check_textures_keys(array[i], "SO ", 3) == -1)
			return (free_array(array), -1);
		else if (check_textures_keys(array[i], "WE ", 3) == -1)
			return (free_array(array), -1);
		else if (check_textures_keys(array[i], "EA ", 3) == -1)
			return (free_array(array), -1);
		else if (check_textures_keys(array[i], "C ", 2) == -1)
			return (free_array(array), -1);
		else if (check_textures_keys(array[i], "F ", 2) == -1)
			return (free_array(array), -1);
		if (is_line_is_map(array[i]))
            return (0);
		i++;
	}
    return (0);
}

char    **copy_file(int fd)
{
    char    *line;
    char    **array;

    array = NULL;
    line = get_next_line(fd);
    while (line)
    {
        array = map_addline(array, line);
        free(line);
        line = get_next_line(fd);
    }
    return (array);
}
