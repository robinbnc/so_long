/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:57:17 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/07 23:31:47 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <sys/types.h>
# include <stdint.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include "../minilibx/mlx.h"
# include "definitions.h"
# include "struct.h"

int			ft_strlen(char *s);
char		*get_next_line(int fd);
char		*ft_strdup(char *s);
int			correct_map(t_map *map);
t_window	ft_new_window(t_program *program, int width,
				int height, char *name);
void		sprites_init(t_program	*program);
int			draw_map(t_program *program);
int			game_winned(t_program *program);
void		init_game(t_program *program);
int			init_map(char *map, t_map *map_struct);
int			ft_input(int keycode, t_program *program);
void		window_resolution(t_program *program);
int			ft_close(t_program *program);
int			ft_error(t_program	*program, int ac, char *av[]);
t_image		ft_new_sprite(t_program *prgm, char *path);
void		destroy_player(t_program *prgm);
void		clear_map(t_program *program);
void		free_strs(char **strs);
void		free_strs_from_end(char **strs, int index);
int			ft_strlen_gnl(char *s);
void		remove_line_break(t_map *map_struct);

#endif