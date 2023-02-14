/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:41:47 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/07 23:32:20 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i])
		return (i + 1);
	else
		return (i);
}

void	free_strs_from_end(char **strs, int index)
{
	while (index > 0)
	{
		free(strs[index]);
		index--;
	}
	free(strs[index]);
	free(strs);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs[i]);
	free(strs);
}

void	remove_line_break(t_map *map_struct)
{
	int	i;

	i = map_struct->size.y - 1;
	while (map_struct->ptr[i][0] == '\n')
		i--;
	map_struct->size.y = i + 1;
}
