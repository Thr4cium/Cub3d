#include "../headers/cub3d.h"

void	move_player(t_game *game, float move_x, float move_y)
{
	float		new_x;
	float		new_y;

	new_x = game->pos_x + (move_x * MV_SPEED);
	new_y =	game->pos_y + (move_y * MV_SPEED);
	if (game->map->map[(int)new_y][(int)new_x] == '1')
		return ;
	if (game->map->map[(int)game->pos_y][(int)new_x] != '1')
		game->pos_x = new_x;
	if (game->map->map[(int)new_y][(int)game->pos_x] != '1')
		game->pos_y = new_y;
}

/*
*	rotation matrix for 2D space
*	theta is the vector
*	cos(theta) - sin(theta)
*	cos(theta) + sin(theta)
*/
void	rotate(t_game *game, float rotation_speed)
{
	float		old_dir_x;
	float		old_plane_x;

	old_dir_x = game->dir_x;
	old_plane_x = game->plane_x;
	game->dir_x = (game->dir_x * cos(rotation_speed))
		- (game->dir_y * sin(rotation_speed));
	game->dir_y = (old_dir_x * sin(rotation_speed))
		+ (game->dir_y * cos(rotation_speed));
	game->plane_x = (game->plane_x * cos(rotation_speed))
		- (game->plane_y * sin(rotation_speed));
	game->plane_y = (old_plane_x * sin(rotation_speed))
		+ (game->plane_y * cos(rotation_speed));
}