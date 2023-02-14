/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:58:54 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/07 15:22:06 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int ac, char *av[])
{
	t_program	program;

	if (ft_error(&program, ac, av))
		return (0);
	init_game(&program);
	program.mlx = mlx_init();
	if (program.mlx == NULL)
		return (0);
	sprites_init(&program);
	window_resolution(&program);
	program.window = ft_new_window(&program, program.window.width,
			program.window.height, "SO LONG");
	draw_map(&program);
	mlx_key_hook(program.window.reference, ft_input, &program);
	mlx_loop(program.mlx);
	return (0);
}
