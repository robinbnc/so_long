/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:15:58 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/07 23:42:55 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

static int	nb_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		nbr_len;

	nbr_len = nb_len(n);
	nbr = malloc(sizeof(char) * (nbr_len + 1));
	if (nbr == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(nbr, "-2147483648", 12);
		return (nbr);
	}
	nbr[nbr_len] = '\0';
	if (n < 0)
	{
		n = -n;
		nbr[0] = '-';
	}
	while (n > 9)
	{
		nbr[--nbr_len] = n % 10 + 48;
		n /= 10;
	}
	nbr[--nbr_len] = n % 10 + 48;
	return (nbr);
}

char	*ft_strcat(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[j + i] = '\0';
	return (dest);
}
