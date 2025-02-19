/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:26:23 by magrondi          #+#    #+#             */
/*   Updated: 2024/12/19 14:26:42 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	set_keys(t_keys *keys)
{
	keys->esc = false;
	keys->w = false;
	keys->s = false;
	keys->a = false;
	keys->d = false;
	keys->left = false;
	keys->right = false;
	keys->is_pristine = true;
}

void	set_map_pars(t_map_pars *map_pars)
{
	map_pars->no = 0;
	map_pars->so = 0;
	map_pars->we = 0;
	map_pars->ea = 0;
	map_pars->c = 0;
	map_pars->f = 0;
}

void	set_img(t_my_img *img)
{
	img->ptr = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

void	set_ray(t_ray *ray)
{
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->perp_wall_dist = 0;
	ray->wall_x = 0;
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}
