/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:34:50 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/07 22:12:17 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	else if (program->map.ptr[y][x] == 'S')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites[NMY].reference, x * square_size, y * square_size);
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

int	draw_mooves(t_program *program)
{
	char	*str_moves;
	char	*nbr;

	nbr = ft_itoa(program->mooves);
	str_moves = ft_strcat("movements: ", nbr);
	if (!str_moves)
		return (ft_close(program));
	mlx_string_put(program->mlx, program->window.reference,
		program->map.size.x * program->square_size - 3 * program->square_size,
		program->square_size / 2, 16777215, str_moves);
	free(str_moves);
	free(nbr);
	return (0);
}

int	draw_map(t_program *program)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	enemy_mooves(program);
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
	draw_rectangles(program);
	draw_mooves(program);
	return (0);
}
