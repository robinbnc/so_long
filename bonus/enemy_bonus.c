/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:28:40 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/02 19:18:48 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_enemy_pos(t_program *prgm)
{
	t_vector	pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.y < prgm->map.size.y)
	{
		while (pos.x < prgm->map.size.x)
		{
			if (prgm->map.ptr[pos.y][pos.x] == 'S')
			{
				prgm->enemy.exist = 1;
				prgm->enemy.pos.y = pos.y;
				prgm->enemy.pos.x = pos.x;
				return ;
			}
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
}

void	enemy_mooves(t_program *prgm)
{
	int	random_x;
	int	random_y;

	random_x = rand() % prgm->map.size.x;
	random_y = rand() % prgm->map.size.y;
	if (prgm->mooves % 5 == 0 && prgm->map.ptr[random_y][random_x] == '0'
		&& prgm->enemy.exist == 1)
	{
		prgm->map.ptr[prgm->enemy.pos.y][prgm->enemy.pos.x] = '0';
		prgm->map.ptr[random_y][random_x] = 'S';
		prgm->enemy.pos.y = random_y;
		prgm->enemy.pos.x = random_x;
	}
}

void	death_animation(t_program *prgm, int i)
{
	destroy_player(prgm);
	if (i == 0)
		prgm->sprites[PLAYER] = ft_new_sprite(prgm,
				"./textures/player_front.xpm");
	else if (i == 1)
		prgm->sprites[PLAYER] = ft_new_sprite(prgm,
				"./textures/player_right.xpm");
	else if (i == 2)
		prgm->sprites[PLAYER] = ft_new_sprite(prgm,
				"./textures/player_back.xpm");
	else if (i == 3)
		prgm->sprites[PLAYER] = ft_new_sprite(prgm,
				"./textures/player_left.xpm");
	else if (i == 4)
		prgm->sprites[PLAYER] = ft_new_sprite(prgm,
				"./textures/player_front.xpm");
	else
		prgm->sprites[PLAYER] = ft_new_sprite(prgm,
				"./textures/grave.xpm");
}

void	death(t_program *program)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		death_animation(program, i);
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites[PLAYER].reference,
			program->map.player_coord.x * program->square_size,
			program->map.player_coord.y * program->square_size);
		usleep(100000);
		i++;
	}
}
