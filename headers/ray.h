/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:33:04 by magrondi          #+#    #+#             */
/*   Updated: 2025/01/27 02:24:25 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <stdbool.h>

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

typedef struct s_rayon
{
	float	tmp_dir_x;
	float	tmp_dir_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		distance;
	float	wall_x;
	float	wall_y;
	double	perp_wall_dist;
	double	wall_height;
	int		draw_start;
	int		draw_end;
}	t_rayon;

#endif
