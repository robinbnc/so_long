/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:24:03 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/07 23:37:19 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clear_map(t_program *program)
{
	int	y;

	y = 0;
	while (program->map.ptr[y])
	{
		free(program->map.ptr[y]);
		y++;
	}
	free(program->map.ptr);
}

int	ft_close(t_program *program)
{
	if (program->map.ptr != NULL)
		clear_map(program);
	if (program->sprites[WALL].reference != NULL)
		mlx_destroy_image(program->mlx, program->sprites[WALL].reference);
	if (program->sprites[COIN].reference != NULL)
		mlx_destroy_image(program->mlx, program->sprites[COIN].reference);
	if (program->sprites[GROUND].reference != NULL)
		mlx_destroy_image(program->mlx, program->sprites[GROUND].reference);
	if (program->sprites[PLAYER].reference != NULL)
		mlx_destroy_image(program->mlx, program->sprites[PLAYER].reference);
	if (program->sprites[EXIT].reference != NULL)
		mlx_destroy_image(program->mlx, program->sprites[EXIT].reference);
	if (program->sprites[NMY].reference != NULL)
		mlx_destroy_image(program->mlx, program->sprites[NMY].reference);
	if (program->window.reference != NULL)
		mlx_destroy_window(program->mlx, program->window.reference);
	if (program->mlx != NULL)
		mlx_destroy_display(program->mlx);
	if (program->mlx)
		free(program->mlx);
	exit(0);
}

int	map_path_error(char *path, char *ext)
{
	int	i;
	int	j;

	i = 0;
	j = 3;
	while (path[i])
		i++;
	i--;
	while (j >= 0)
	{
		if (path[i] != ext[j])
			return (TRUE);
		j--;
		i--;
	}
	if (i < 0)
		return (TRUE);
	return (FALSE);
}

void	destroy_player(t_program *prgm)
{
	if (prgm->sprites[PLAYER].reference)
		mlx_destroy_image(prgm->mlx, prgm->sprites[PLAYER].reference);
}

int	ft_error(t_program	*program, int ac, char *av[])
{
	int	map_init;
	int	map_error;

	if (ac != 2)
		return (printf("Error\nYou must have one argument\n"), TRUE);
	else if (map_path_error(av[1], ".ber"))
		return (printf("Error\nThe map path must be terminated by .ber\n"), TRUE);
	map_init = init_map(av[1], &program->map);
	if (map_init == -2)
		return (printf("Error\nHeap allocation error\n"), TRUE);
	else if (map_init == -1)
		return (printf("Error\nOpening fils went wrong\n"), TRUE);
	map_error = correct_map(&program->map);
	if (map_error == -2)
	{
		free_strs(program->map.ptr);
		return (printf("Error\nError extrem line must be composed of 1\n"), TRUE);
	}
	else if (!map_error)
	{
		free_strs(program->map.ptr);
		return (printf("Error\nError in map structure\n"), TRUE);
	}
	return (FALSE);
}
