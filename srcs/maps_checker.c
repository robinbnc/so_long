/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:43:25 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/07 23:26:40 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	check_extrem_lines(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_objects(char *str, int *exit, int *collect, int *start)
{
	int	i;

	i = 0;
	if (str[i] != '1')
		return (FALSE);
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != 'P')
			return (FALSE);
		else if (str[i] == 'C')
			*collect += 1;
		else if (str[i] == 'E')
			*exit += 1;
		else if (str[i] == 'P')
			*start += 1;
		i++;
	}
	if (i < 2 || str[i - 1] != '1')
		return (FALSE);
	return (TRUE);
}

int	correct_map(t_map *map)
{
	int			len;
	int			i;
	static int	els[3];

	len = line_len(map->ptr[0]);
	if (!check_extrem_lines(map->ptr[0]))
		return (-2);
	i = 1;
	while (i < map->size.y - 1)
	{
		if (line_len(map->ptr[i]) != len)
			return (FALSE);
		if (!check_objects(map->ptr[i], &els[0], &els[1], &els[2]))
			return (FALSE);
		i++;
	}
	if (!check_extrem_lines(map->ptr[i])
		|| line_len(map->ptr[i]) != map->size.x)
		return (-2);
	if (els[0] != 1 || els[2] != 1 || els[1] < 1)
		return (FALSE);
	return (TRUE);
}
