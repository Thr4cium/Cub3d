/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:48:18 by magrondi          #+#    #+#             */
/*   Updated: 2024/12/16 17:48:19 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	clean_mlx(t_game *game)
{
	if (!game)
		return ;
	if (game->img && game->img->ptr && game->mlx_ptr)
		mlx_destroy_image(game->mlx_ptr, game->img->ptr);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	ft_free(game->img);
	ft_free(game->mlx_ptr);
}
