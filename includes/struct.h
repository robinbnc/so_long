/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:42:08 by rbicanic          #+#    #+#             */
/*   Updated: 2022/01/24 20:42:06 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_enemy
{
	int			exist;
	t_vector	pos;
}				t_enemy;

typedef struct s_window {
	void		*reference;
	t_vector	size;
	int			width;
	int			height;
}				t_window;

typedef struct s_map {
	char		**ptr;
	t_vector	size;
	t_vector	player_coord;
	t_vector	exit;
}				t_map;

typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_program {
	void		*mlx;
	int			mooves;
	int			collectibles;
	int			win;
	int			square_size;
	t_image		img;
	t_window	window;
	t_image		sprites[6];
	t_map		map;
	t_enemy		enemy;
}				t_program;

#endif