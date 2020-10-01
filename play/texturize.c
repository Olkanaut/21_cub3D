/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 21:28:47 by bshang            #+#    #+#             */
/*   Updated: 2020/09/18 12:06:26 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

UI		create_trgb(UI t, UI r, UI g, UI b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	set_colors(t_head *head)
{
	head->txtr->color_ceil = create_trgb(0, head->scan->ceiling[0],
	head->scan->ceiling[1], head->scan->ceiling[2]);
	head->txtr->color_floor = create_trgb(0, head->scan->floor[0],
	head->scan->floor[1], head->scan->floor[2]);
}

void	get_color(t_t *data, int x, int y, UI *color)
{
	char	*dst;

	dst = data->data + (y * data->llen + x * (data->bpp / 8));
	*color = *(UI*)dst;
}

void	check_texture(t_head *head, t_t *side)
{
	head->obst->img_width = side->img_width;
	head->obst->img_height = side->img_height;
}

void	get_txtr_details(t_head *h, int flag, int x, int y)
{
	if (h->obst->side == 'n')
		flag == 1 ? check_texture(h, h->txtr->no) : get_color(h->txtr->no,
		x, y, &h->obst->color);
	if (h->obst->side == 'e')
		flag == 1 ? check_texture(h, h->txtr->ea) : get_color(h->txtr->ea,
		x, y, &h->obst->color);
	if (h->obst->side == 's')
		flag == 1 ? check_texture(h, h->txtr->so) : get_color(h->txtr->so,
		x, y, &h->obst->color);
	if (h->obst->side == 'w')
		flag == 1 ? check_texture(h, h->txtr->we) : get_color(h->txtr->we,
		x, y, &h->obst->color);
}
