/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:39:29 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/07 14:58:03 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_shift(int keycode, t_vector *dest, t_program *prgm)
{
	destroy_player(prgm);
	if (keycode == XK_w)
	{
		prgm->sprites[PLAYER] = ft_new_sprite(prgm,
				"./textures/player_back.xpm");
		dest->y--;
	}
	else if (keycode == XK_a)
	{
		prgm->sprites[PLAYER] = ft_new_sprite(prgm,
				"./textures/player_left.xpm");
		dest->x--;
	}
	else if (keycode == XK_d)
	{
		prgm->sprites[PLAYER] = ft_new_sprite(prgm,
				"./textures/player_right.xpm");
		dest->x++;
	}	
	else if (keycode == XK_s)
	{
		prgm->sprites[PLAYER] = ft_new_sprite(prgm,
				"./textures/player_front.xpm");
		dest->y++;
	}
}

void	update_position(t_program *prgm, t_vector dest)
{
	prgm->mooves++;
	prgm->map.ptr[dest.y][dest.x] = 'P';
	prgm->map.ptr[prgm->map.player_coord.y][prgm->map.player_coord.x] = '0';
	prgm->map.player_coord.x = dest.x;
	prgm->map.player_coord.y = dest.y;
	draw_map(prgm);
}

void	win_message(t_program *program)
{
	printf("\t**********************************\n");
	printf("\t*            YOU WON             *\n");
	printf("\t*                                *\n");
	printf("\t**********************************\n");
	ft_close(program);
}

void	loose_message(void)
{
	printf("\t**********************************\n");
	printf("\t*                                *\n");
	printf("\t*             LOOSER             *\n");
	printf("\t*                                *\n");
	printf("\t**********************************\n");
}

int	ft_input(int keycode, t_program *program)
{
	t_vector	dest;

	if (keycode == XK_Escape)
		ft_close(program);
	if ((keycode != XK_w && keycode != XK_a
			&& keycode != XK_d && keycode != XK_s) || program->win)
		return (0);
	dest = program->map.player_coord;
	ft_shift(keycode, &dest, program);
	if (program->map.ptr[dest.y][dest.x] == 'C')
		program->collectibles--;
	else if (program->map.ptr[dest.y][dest.x] == '1' ||
		(program->map.ptr[dest.y][dest.x] == 'E' && program->collectibles > 0))
		return (0);
	else if (program->map.ptr[dest.y][dest.x] == 'S')
	{
		program->win = -1;
		death(program);
		loose_message();
		return (0);
	}	
	update_position(program, dest);
	if (game_winned(program))
		win_message(program);
	return (0);
}
