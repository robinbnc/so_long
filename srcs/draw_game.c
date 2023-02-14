/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:34:50 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/07 22:07:58 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_sprites(t_program *program, int square_size, int x, int y)
{
	if (program->map.ptr[y][x] == '1')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites[WALL].reference, x * square_size, y * square_size);
	else if (program->map.ptr[y][x] == '0')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites[GROUND].reference,
			x * square_size, y * square_size);
	else if (program->map.ptr[y][x] == 'C')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites[COIN].reference, x * square_size, y * square_size);
	else if (program->map.ptr[y][x] == 'P')
	{
		program->map.player_coord.x = x;
		program->map.player_coord.y = y;
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites[PLAYER].reference,
			x * square_size, y * square_size);
	}
	else if (program->map.ptr[y][x] == 'E')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites[EXIT].reference, x * square_size, y * square_size);
}

void	draw_rectangles(t_program *program)
{
	t_vector	pos;
	int			square;

	pos.x = 0;
	pos.y = 0;
	square = program->square_size;
	while (pos.y < program->square_size)
	{
		while (pos.x < program->square_size * 3)
		{
			mlx_pixel_put(program->mlx, program->window.reference,
				program->map.size.x * square - 3 * square + pos.x, pos.y, 0);
			pos.x++;
		}
		pos.y++;
		pos.x = 0;
	}
}

int	draw_map(t_program *program)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < program->map.size.y)
	{
		while (x < program->map.size.x)
		{
			ft_put_sprites(program, program->square_size, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
