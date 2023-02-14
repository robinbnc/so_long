/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:39:25 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/08 16:22:51 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	window_resolution(t_program *program)
{
	program->square_size = program->sprites[WALL].size.x;
	program->window.width = program->square_size * program->map.size.x;
	program->window.height = program->square_size * program->map.size.y;
}

t_window	ft_new_window(t_program *program, int width, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(program->mlx, width, height, name);
	window.size.x = width;
	window.size.y = height;
	mlx_hook(window.reference, ON_DESTROY, 0, ft_close, program);
	return (window);
}
