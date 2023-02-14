/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:40:12 by rbicanic          #+#    #+#             */
/*   Updated: 2022/01/21 22:27:05 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H
# define BUFFER_SIZE 100
# define TRUE 1
# define FALSE 0
# define WIDTH 500
# define HEIGHT 500

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	WALL = 0,
	PLAYER = 1,
	COIN = 2,
	GROUND = 3,
	EXIT = 4,
	NMY = 5
};

#endif