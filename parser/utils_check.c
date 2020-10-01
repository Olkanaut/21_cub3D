/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:45:09 by bshang            #+#    #+#             */
/*   Updated: 2020/09/18 22:22:11 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

int		check_fname(char *name, int fd)
{
	char	*p;

	if (!(p = ft_strrchr(name, '.')))
		return (finalize(fd, ERR_ARG));
	if (ft_strncmp(p, ".cub", -1) != 0)
		return (finalize(fd, ERR_ARG));
	return (0);
}

int		check_scrshot_flag(char *name, t_scanned *scanned)
{
	if (ft_strncmp(name, "--save", -1) == 0)
	{
		scanned->save_f = 1;
		return (1);
	}
	return (-1);
}

int		is_obj(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (3);
	if (c == '2')
		return (2);
	if (c == '0')
		return (8);
	return (0);
}

int		check_f(int *flags)
{
	int		i;

	i = 0;
	while (i < 13)
	{
		if (flags[i] != 1)
			return (ERR_FILE);
		i++;
	}
	return (0);
}
