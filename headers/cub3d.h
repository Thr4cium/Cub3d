/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:30:04 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/12 13:21:59 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

typedef struct s_map
{
    int		res_x;
    int		res_y;
    char	*no_texture;
    char	*so_texture;
    char	*we_texture;
    char	*ea_texture;
    char	*s_texture;
    char	**map;
    int		map_x;
    int		map_y;
}				t_map;

typedef struct s_game
{
    t_map	*map;
}				t_game;