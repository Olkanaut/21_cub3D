/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 13:37:45 by bshang            #+#    #+#             */
/*   Updated: 2020/09/20 19:48:23 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

static char	*skip(char *p, char a)
{
	if (a == ' ')
		while (*p == a)
			p++;
	else if (a == ',')
		while (*p == a)
			p++;
	else if (a == 'n')
		while (*p >= '0' && *p <= '9')
			p++;
	else if (a == 'z')
	{
		p = skip(p, 'n');
		p = skip(p, ' ');
	}
	return (p);
}

int			read_colors(char a, char *p, int *color, int *flags)
{
	p = skip(p, ' ');
	color[0] = ft_atoi(p);
	if (color[0] > 255)
		return (ERR_FILE);
	if ((p = skip(p, 'z')) && *p != ',')
		return (ERR_FILE);
	if (p++ && (p = skip(p, ' ')) && ft_isdigit(*p) == 0)
		return (ERR_FILE);
	if ((color[1] = ft_atoi(p)) && color[1] > 255)
		return (ERR_FILE);
	if ((p = skip(p, 'z')) && *p != ',')
		return (ERR_FILE);
	if (p++ && (p = skip(p, ' ')) && ft_isdigit(*p) == 0)
		return (ERR_FILE);
	if ((color[2] = ft_atoi(p)) && color[2] > 255)
		return (ERR_FILE);
	p = skip(p, 'z');
	if (*p != '\n' && *p != '\0')
		return (ERR_FILE);
	a == 'F' ? flags[2]++ : flags[5]++;
	a == 'F' ? flags[3]++ : flags[6]++;
	a == 'F' ? flags[4]++ : flags[7]++;
	return (0);
}

int			read_res(char *p, int *res, int *flags)
{
	p = skip(p, ' ');
	res[0] = ft_atoi(p);
	if (res[0] < 1)
		return (ERR_FILE);
	if (res[0] < 100)
		res[0] = 100;
	p = skip(p, 'n');
	res[1] = ft_atoi(p);
	if (res[1] < 1)
		return (ERR_FILE);
	if (res[1] < 100)
		res[1] = 100;
	p = skip(p, ' ');
	p = skip(p, 'n');
	p = skip(p, ' ');
	if (*p != ' ' && *p != '\n' && *p != '\0')
		return (ERR_FILE);
	flags[0]++;
	flags[1]++;
	return (0);
}

int			read_map(char *line, t_scanned *scan)
{
	t_list	*new;

	new = ft_lstnew(ft_strdup(line));
	if (!new)
		return (ERR_MEM);
	new->content_size = ft_strlen(line);
	if (new->content_size > scan->map_size[0])
		scan->map_size[0] = new->content_size;
	scan->map_size[1]++;
	ft_lstadd_back(&scan->raw_map, new);
	return (0);
}

int			read_file_link(char a, char *p, char **link, int *flags)
{
	char	*s;
	int		fd;

	p += 2;
	s = skip(p, ' ');
	if (!(*link = ft_substr((char const*)s, 0, ft_strlen(s))))
		return (ERR_MEM);
	if ((fd = open(*link, O_RDONLY)) < 0)
		return (ERR_OPEN);
	if (a == 'N' || a == 'S')
		a == 'N' ? flags[8]++ : flags[9]++;
	else if (a == 'Z')
		flags[12]++;
	else
		a == 'E' ? flags[10]++ : flags[11]++;
	return (0);
}
