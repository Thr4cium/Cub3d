/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:30:04 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/21 15:26:27 by rolamber         ###   ########.fr       */
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
# include <sys/types.h>

typedef struct s_map
{
	int		res_x;
	int		res_y;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	**map;
	int		ground_color;
	int 	sky_color;
	int		map_x;
	int		map_y;
}				t_map;

typedef struct s_game
{
	t_map	*map;
}				t_game;

#endif

// main

void	init_game_struct(t_game *game);
void	print_map_info(t_game *game);

// parsing_routine

int		parsing(char *path, t_game *game);
int		get_information(char *path, t_map *map);
int		get_map_information(t_map *map, int fd);
char	**map_addline(char **map, char *line);
int		check_map_information(t_map *map);
int		check_map_validity(t_map *map);
void	free_all(t_game *game);
int		check_path(char *path);

// parsing_tools

t_map	*init_map(void);
bool	are_texture_filled(t_map *map);
bool	is_line_only_empty(char *line);
bool	is_line_is_map(char *line);
bool	is_line_only_map(char *line);

// texture_informations

int	get_texture_information(t_map *map, int fd);
int check_texture_information(t_map *map);
int	check_color_information(t_map *map);
int	rgb_to_int(char *line);
int rgb_to_int_tool(int j, char *colorm, int rgb);