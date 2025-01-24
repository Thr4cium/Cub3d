/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:32:05 by magrondi          #+#    #+#             */
/*   Updated: 2025/01/24 00:55:22 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "map.h"
# include "my_img.h"
# include "map_pars.h"
# include "keys.h"
# include "texture.h"

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

#endif