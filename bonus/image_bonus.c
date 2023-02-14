/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:32:48 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/02 19:49:09 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_image	ft_new_sprite(t_program *prgm, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(prgm->mlx, path, &img.size.x,
			&img.size.y);
	if (img.reference == NULL)
	{
		printf("Error\nSprite path \"%s\" does not exist !\n", path);
		ft_close(prgm);
	}
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

void	sprites_init(t_program	*program)
{
	program->sprites[WALL].reference = NULL;
	program->sprites[PLAYER].reference = NULL;
	program->sprites[COIN].reference = NULL;
	program->sprites[GROUND].reference = NULL;
	program->sprites[EXIT].reference = NULL;
	program->sprites[NMY].reference = NULL;
	program->sprites[WALL] = ft_new_sprite(program,
			"./textures/wall.xpm");
	program->sprites[PLAYER] = ft_new_sprite(program,
			"./textures/player.xpm");
	program->sprites[COIN] = ft_new_sprite(program,
			"./textures/coin.xpm");
	program->sprites[GROUND] = ft_new_sprite(program,
			"./textures/ground.xpm");
	program->sprites[EXIT] = ft_new_sprite(program, "./textures/exit.xpm");
	program->sprites[NMY] = ft_new_sprite(program,
			"./textures/enemy_front.xpm");
}
