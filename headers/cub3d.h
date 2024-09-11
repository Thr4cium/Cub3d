/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:30:04 by rolamber          #+#    #+#             */
/*   Updated: 2024/09/11 16:51:20 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include "../libmlx/mlx.h"
# include "../libmlx/mlx_int.h"
# include <stdio.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define PI 3.1415926535
# define MINIMAP_RANGE 5

typedef struct s_ray
{
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
}	t_ray;

typedef	struct s_my_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int 	endian;
}			t_my_img;

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
	size_t		map_x;
	size_t		map_y;
}				t_map;

typedef struct s_game
{
	t_map		*map;
	t_my_img	*img;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	void	*mlx_ptr;
	void	*win_ptr;
	int		tile_size;
	double  center_x;
	double  center_y;
	bool	key_pressed;
	bool	keys[256];
}				t_game;


typedef enum e_move
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}				t_move;

// main
void	game_loop(t_game *game);
void	init_game_struct(t_game *game);
void	print_map_info(t_game *game);
int		end_game(t_game *game);
void	init_mlx(t_game *game);


// parsing_routine

int		parsing(char *path, t_game *game);
int		get_information(char *path, t_map *map);
int		get_map_information(t_map *map, int fd);
char	**map_addline(char **map, char *line);
int		check_map_information(t_map *map);
int		check_map_validity(t_map *map);
void	free_all(t_game *game);
int		check_path(char *path);
void	actualise_map(t_map *map);


// parsing_tools

t_map	*init_map(void);
bool	are_texture_filled(t_map *map);
bool	is_line_only_empty(char *line);
bool	is_line_is_map(char *line);
bool	is_line_only_map(char *line);

// texture_informations

int		get_texture_information(t_map *map, int fd);
int 	check_texture_information(t_map *map);
int		check_color_information(t_map *map);
int		rgb_to_int(char *line);
int		rgb_to_int_tool(int j, char *colorm, int rgb);
char	*ft_strdup_trim(char *line);

// display_game
int		display_game(t_game *game);
void	print_minimap(t_game *game);
void    draw_tile(t_game *game, double start_x, double start_y, int color);
void    draw_line(t_game *game, int x, int y, int color);
void    set_window_color(t_game *game, int color);

// display_utils
void	my_mlx_pixel_put(t_my_img *img, int x, int y, int color);
int		secure_my_mlx_pixel_put(t_my_img *img, int x, int y, int color);
int secure_my_mlx_pixel_put2(t_my_img *img, int x, int y, int color);
void    print_player(t_game *game, int x, int y, int r);
void    draw_round(t_game *game, double x, double y, int r, int color);
void    print_minimap_background(t_game *game, int color);

// init_vectors
void    init_vectors(t_game *game);
void    init_dir_vectors(t_game *game);

// map_information
void	get_player_initial_position(t_game *game);

// movement
int		update_game(t_game *game);
int		key_input(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void    move(t_game *game, t_move move);
bool    is_there_wall(t_game *game, t_move move);


// minimap_rays
void	print_rays(t_game *game);
void    ray_casting(t_game *game);
int ray_cast(t_game *game, double Vdir_x, double Vdir_y, int i);
void    init_ray(t_game *game, t_ray *ray, double Vdir_x, double Vdir_y);
void    init_ray2(t_game *game, t_ray *ray, double Vdir_x, double Vdir_y);
void    dda_algorithm(t_game *game, t_ray *ray);
void    define_wall_line(t_game *game, t_ray *ray, int x, int color);


#endif