/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:29:04 by bshang            #+#    #+#             */
/*   Updated: 2020/09/18 11:53:28 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

double	to_degrees(double radians)
{
	return (radians * (180.0 / M_PI));
}

double	to_rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

char	*even_string(char *m, size_t size_max)
{
	char	*res;
	size_t	p;
	size_t	len;
	size_t	i;

	len = ft_strlen(m) + 1;
	i = 0;
	while (i < len)
	{
		if (m[i] == ' ')
			m[i] = '.';
		i++;
	}
	if (len - 1 < size_max)
	{
		if (!(res = (char*)malloc(sizeof(char) * (size_max + 1))))
			return (NULL);
		p = ft_strlcpy(res, m, len);
		while (p < size_max)
			res[p++] = '.';
		res[size_max] = '\0';
		free(m);
		return (res);
	}
	return (m);
}

void	set_scanned_struct(t_scanned *scanned)
{
	scanned->path_no = NULL;
	scanned->path_so = NULL;
	scanned->path_ea = NULL;
	scanned->path_we = NULL;
	scanned->sprite = NULL;
	scanned->spr_c = 0;
	ft_bzero(scanned->floor, sizeof(int));
	ft_bzero(scanned->ceiling, sizeof(int));
	ft_bzero(scanned->res, sizeof(int));
	scanned->raw_map = NULL;
	scanned->flag = 0;
	ft_bzero(scanned->map_size, sizeof(size_t));
	scanned->save_f = 0;
	scanned->bonus_f = 0;
	ft_bzero(scanned->f_val, sizeof(int));
}
