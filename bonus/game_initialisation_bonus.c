/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialisation_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:37:08 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/08 16:21:58 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_objectives(t_program *program)
{
	int	x;
	int	y;
	int	coins;

	x = 0;
	y = 0;
	coins = 0;
	while (y < program->map.size.y)
	{
		while (x < program->map.size.x)
		{
			if (program->map.ptr[y][x] == 'C')
				coins++;
			else if (program->map.ptr[y][x] == 'E')
			{
				program->map.exit.x = x;
				program->map.exit.y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	program->collectibles = coins;
}

void	init_game(t_program *program)
{
	program->mooves = 0;
	program->win = 0;
	program->enemy.exist = 0;
	init_objectives(program);
	check_enemy_pos(program);
}

int	game_winned(t_program *program)
{
	if (program->map.player_coord.x == program->map.exit.x
		&& program->map.player_coord.y == program->map.exit.y)
	{
		program->win = 1;
		return (TRUE);
	}	
	return (FALSE);
}

int	get_map_height(char *map, t_map *map_struct)
{
	int		fd;
	int		nbr_of_lines;
	char	*str;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	nbr_of_lines = 0;
	str = get_next_line(fd);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		free(str);
		nbr_of_lines++;
	}
	close(fd);
	map_struct->ptr = malloc(sizeof(char *) * (nbr_of_lines + 1));
	if (map_struct->ptr == NULL)
		return (1);
	map_struct->size.y = nbr_of_lines;
	return (0);
}

int	init_map(char *map, t_map *map_struct)
{
	int		fd;
	int		i;

	if (map == NULL)
		return (-2);
	if (get_map_height(map, map_struct))
		return (-1);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 0;
	map_struct->ptr[i] = get_next_line(fd);
	if (!map_struct->ptr[i])
		return (close(fd), free_strs_from_end(map_struct->ptr, i), 0);
	while (map_struct->ptr[i])
	{
		i++;
		map_struct->ptr[i] = get_next_line(fd);
	}
	close(fd);
	map_struct->size.x = ft_strlen(map_struct->ptr[0]) - 1;
	remove_line_break(map_struct);
	return (1);
}
