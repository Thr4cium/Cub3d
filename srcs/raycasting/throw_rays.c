/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:59:12 by magrondi          #+#    #+#             */
/*   Updated: 2025/01/27 10:12:10 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	get_color_test(t_texture *texture, t_rayon *ray, int x, int delta)
{
	char	*ptr;
	int		color;
	int		texx;
	int		texy;
	int		y;

	texx = ray->wall_x * texture->width;
	if (ray->side == 0 && ray->tmp_dir_x > 0)
		texx = texture->width - texx - 1;
	if (ray->side == 1 && ray->tmp_dir_y < 0)
		texx = texture->width - texx - 1;
	if (delta > SCREEN_HEIGHT)
	{
		y = ((delta - SCREEN_HEIGHT) / 2) * texture->height / delta;
		texy = y + x * texture->height / delta;
	}
	else
		texy = x * texture->height / delta;
	ptr = texture->addr + (texy * texture->line_length + \
		texx * (texture->bits_per_pixel / 8));
	color = *(unsigned int *)ptr;
	return (color);
}

void	draw_scaled_wall_test(t_game *game, int x, t_rayon *ray)
{
	int	color;
	int	delta;
	int	i;

	delta = ray->draw_end - ray->draw_start;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	i = 0;
	while (ray->draw_start < ray->draw_end)
	{
		if (ray->side == 1 && ray->step_y == -1)
			color = get_color_test(game->so_img, ray, i, delta);
		else if (ray->side == 1 && ray->step_y == 1)
			color = get_color_test(game->no_img, ray, i, delta);
		else if (ray->side == 0 && ray->step_x == -1)
			color = get_color_test(game->ea_img, ray, i, delta);
		else if (ray->side == 0 && ray->step_x == 1)
			color = get_color_test(game->we_img, ray, i, delta);
		secure_my_mlx_pixel_put2(game->img, x, ray->draw_start, color);
		i++;
		ray->draw_start++;
	}
}
