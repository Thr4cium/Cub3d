/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:30:04 by rolamber          #+#    #+#             */
/*   Updated: 2024/12/19 17:36:16 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include "../libft/libft.h"
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

# ifndef FILE_MAX_HEIGHT
#  define FILE_MAX_HEIGHT 250
# endif

# ifndef FILE_MAX_WIDTH
#  define FILE_MAX_WIDTH 250
# endif

# ifndef GREEN
#  define GREEN 0x0000FF00
# endif

# ifndef BONUS
#  define BONUS 0
# endif

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 1280
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 1024
# endif

# ifndef PI
#  define PI 3.1415926535
# endif

# ifndef MINIMAP_RANGE
#  define MINIMAP_RANGE 5
# endif

# ifndef MLX_CROSS_CODE
#  define MLX_CROSS_CODE 17
# endif

# ifndef MV_SPEED
#  define MV_SPEED 0.21
# endif

# ifndef ROT_SPEED
#  define ROT_SPEED 0.09
# endif

# ifndef NORTH_ANGLE
#  define NORTH_ANGLE 270
# endif

# ifndef WEST_ANGLE
#  define WEST_ANGLE 180
# endif

# ifndef SOUTH_ANGLE
#  define SOUTH_ANGLE 90
# endif

# ifndef EAST_ANGLE
#  define EAST_ANGLE 0
# endif

typedef struct s_map_pars
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	c;
	int	f;
}	t_map_pars;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
	bool	esc;
	bool	is_pristine;
}	t_keys;

typedef struct s_ray
{
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_my_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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
	int		sky_color;
	size_t	map_x;
	size_t	map_y;
}				t_map;

typedef struct s_texture
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_texture;

typedef struct s_game
{
	t_map			*map;
	t_my_img		*img;
	t_map_pars		*map_pars;
	t_keys			*keys;
	void			*win_ptr;
	void			*mlx_ptr;
	t_texture		*so_img;
	t_texture		*no_img;
	t_texture		*we_img;
	t_texture		*ea_img;
	double			mouse_x;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				tile_size;
	double			center_x;
	double			center_y;
	bool			key_pressed;
}				t_game;

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
void		ray_casting(t_game *game);
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

#endif