/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:00:49 by bshang            #+#    #+#             */
/*   Updated: 2020/09/16 15:19:57 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

static int		check_symbols_in_row(char *s, t_head *head)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (is_obj(s[i]) == 0 && s[i] != '1' && s[i] != ' ')
			return (ERR);
		if (is_obj(s[i]) > 0)
			if (i == 0 || s[i + 1] == ' ' || s[i - 1] == ' ' ||
			s[i + 1] == '\0')
				return (ERR);
		if (is_obj(s[i]) == 2)
			head->scan->spr_c++;
		i++;
	}
	return (0);
}

static int		read_player(int j, int i, t_head *head, char orientation)
{
	head->pl->flag++;
	if (head->pl->flag > 1)
		return (ERR);
	head->pl->pos[0] = j;
	head->pl->pos[1] = i;
	if (orientation == 'N')
		head->pl->dir = 0;
	else if (orientation == 'E')
		head->pl->dir = 90;
	else if (orientation == 'S')
		head->pl->dir = 180;
	else
		head->pl->dir = 270;
	return (0);
}

static void		read_sprite(t_head *head, int j, int i)
{
	head->sp_ar[head->scan->spr_c - 1].x = j;
	head->sp_ar[head->scan->spr_c - 1].y = i;
	head->sp_ar[head->scan->spr_c - 1].flag = 0;
	head->sp_ar[head->scan->spr_c - 1].dist = 0.0;
	head->sp_ar[head->scan->spr_c - 1].w = 0.0;
	head->sp_ar[head->scan->spr_c - 1].h = 0.0;
	head->scan->spr_c--;
}

static int		check_symbols_in_col(char **m, size_t *len, t_head *head)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < len[1])
	{
		j = 0;
		if (!(m[i] = even_string(m[i], len[0])))
			return (ERR_MEM);
		while (j < len[0])
		{
			if (is_obj(m[i][j]) > 0 && ((i == 0 || i == len[1] - 1) || (i > 0
			&& i < len[1] - 1 && (m[i - 1][j] == '.' || m[i + 1][j] == '.'))))
				return (ERR_MAP);
			if (m[i][j] == '.' && i > 0 && is_obj(m[i - 1][j]) > 0)
				return (ERR_MAP);
			if (is_obj(m[i][j]) == 3 && read_player(j, i, head, m[i][j]) < 0)
				return (ERR_MAP);
			if (is_obj(m[i][j]) == 2)
				read_sprite(head, j, i);
			j++;
		}
		i++;
	}
	return (head->pl->flag == 1 ? 0 : ERR_MAP);
}

int				convert_raw_to_valid_field(t_head *h)
{
	int		k;
	int		res;
	t_list	*begin;

	if (!(h->map = (char**)malloc(sizeof(char*) * (h->scan->map_size[1] + 1))))
		return (ERR_MEM);
	h->map[h->scan->map_size[1]] = NULL;
	begin = h->scan->raw_map;
	while (h->scan->raw_map)
	{
		*h->map = ft_strdup(h->scan->raw_map->content);
		if (check_symbols_in_row(*h->map, h) < 0)
			return (ERR_MAP);
		h->scan->raw_map = h->scan->raw_map->next;
		h->map++;
	}
	h->map -= h->scan->map_size[1];
	ft_lstclear(&begin, free);
	k = h->scan->spr_c;
	if (!(h->sp_ar = (t_sprite*)malloc(sizeof(t_sprite) * (h->scan->spr_c))))
		return (ERR_MEM);
	if ((res = check_symbols_in_col(h->map, h->scan->map_size, h)) && res < 0)
		return (res == -3 ? ERR_MEM : ERR_MAP);
	h->scan->spr_c = k;
	return (0);
}
