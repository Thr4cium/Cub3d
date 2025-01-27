/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:30:04 by rolamber          #+#    #+#             */
/*   Updated: 2025/01/27 04:09:23 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../libmlx/mlx.h"
# include "../libmlx/mlx_int.h"
# include "macros.h"
# include "map_pars.h"
# include "keys.h"
# include "texture.h"
# include "map.h"
# include "my_img.h"
# include "ray.h"
# include "game.h"
# include <stdio.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef enum e_move
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ROTATE_LEFT,
	ROTATE_RIGHT
}				t_move;

// display_game
int			display_game(t_game *game);
void		set_window_color(t_game *game, int color);
void		print_minimap(t_game *game);
void		draw_line(t_game *game, int x, int y, int color);
void		draw_tile(t_game *game, double start_x, double start_y, int color);
void		print_minimap_perp_rays(t_game *game);

// display_utils
int			secure_my_mlx_pixel_put(t_my_img *img, int x, int y, int color);
int			secure_my_mlx_pixel_put2(t_my_img *img, int x, int y, int color);
void		draw_round(t_game *game, double x, double y, int r);
void		print_player(t_game *game, int x, int y, int r);
void		print_minimap_background(t_game *game, int color);

// movement
int			process_mouse_motion(t_game *game);
int			handle_keypress(int keycode, t_game *game);
int			handle_keyrelease(int keycode, t_game *game);
void		move(t_game *game, t_move move);
void		move_mouse(t_game *game, t_move move, int delta);

// parsing routine bis
int			check_map_information(t_map *map);
int			check_map_validity(t_map *map);
int			check_map_validity_bis(t_map *map);
int			case_first_last_line(t_map *map);
int			check_path(char *path);

// parsing_routine
void		actualise_map(t_map *map);
int			parsing(char *path, t_game *game);
int			get_map_line_information(t_map *map, char **array, int i);

// parsing_edge_case
int			check_textures_keys(char *line, char *str, int n,
				t_map_pars *m_pars);
int			check_edge_cases(char **array, t_map_pars *m_pars);
char		**copy_file(int fd);
void		free_array(char **array);

// parsing_tools

t_map		*init_map(void);
bool		are_texture_filled(t_map *map);
bool		is_line_only_empty(char *line);
bool		is_line_is_map(char *line);
bool		is_line_only_map(char *line);

// ray_cast utils
void		dda_algorithm(t_game *game, t_ray *ray);
void		define_wall_line(t_game *game, t_ray *ray, int x);
void		draw_scaled_wall(t_game *game, int x, t_ray *ray);
void		draw_ground_and_sky(t_game *game, int x,
				int drawStart, int drawEnd);
int			get_color(t_texture *texture, t_ray *ray, int x, int delta);

// ray cast
void		print_rays(t_game *game);
int			ray_cast(t_game *game, t_ray *ray, int i);
void		init_ray(t_game *game, t_ray *ray);
void		init_ray2(t_game *game, t_ray *ray);

// render
bool		is_there_wall(t_game *game, t_move move);
int			update_game(t_game *game);

// texture_informations
int			get_texture_information(t_map *map, char **array);
int			check_texture_information(t_map *map);
int			check_color_information(t_map *map);
int			rgb_to_int(char *line);
int			rgb_to_int_tool(int j, char *colorm, int rgb);

// texture_loading
void		get_player_initial_position(t_game *game);
int			access_texture(char *path);
int			load_textures(t_game *game);

// utils
char		*ft_strdup_trim(char *line);
void		free_textures(t_game *game);
int			end_game(t_game *game);
void		my_mlx_pixel_put(t_my_img *img, int x, int y, int color);
void		free_all(t_game *game);
float		radians_to_degrees(float radians);
float		degrees_to_radians(float degrees);
bool		is_integer(double value);

#endif