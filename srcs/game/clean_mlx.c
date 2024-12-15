#include "../../headers/cub3d.h"

void clean_mlx(t_game *game)
{
	if (game->img)
	{
		if (game->img->ptr && game->mlx_ptr)
			mlx_destroy_image(game->mlx_ptr, game->img->ptr);
		ft_free(game->img);
	}
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		ft_free(game->mlx_ptr);
}

