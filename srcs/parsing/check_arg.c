#include "../../headers/cub3d.h"

int	check_arg(int ac, char **av)
{
	if (ac != 2 && ac != 3)
		return (printf("Error\n wrong number of arguments\n"), -1);
	if (ac == 3 && ft_strncmp(av[2], "--save", 7) != 0)
		return (printf("Error\n wrong argument\n"), -1);
	if (check_path(av[1]) == -1)
		return (-1);
	return (0);
}

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
