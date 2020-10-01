/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 20:56:09 by bshang            #+#    #+#             */
/*   Updated: 2020/09/17 22:39:34 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

void	set_sprite_distances(t_head *h)
{
	int		i;

	i = 0;
	while (i < h->scan->spr_c)
	{
		h->sp_ar[i].dist = calc_d(h->sp_ar[i].x,
		h->pl->pos[0], h->sp_ar[i].y, h->pl->pos[1]);
		i++;
	}
}

void	eat_spr(t_head *h, int x, int y)
{
	int		i;

	i = 0;
	while (i < h->scan->spr_c)
	{
		if (h->sp_ar[i].x == x && h->sp_ar[i].y == y)
		{
			h->sp_ar[i].flag = 0;
			h->im->sp_vis_count--;
			h->im->sp_eaten_count++;
			h->scan->spr_c--;
			break ;
		}
		i++;
	}
}

void	define_spr_and_fill(t_head *h, double ray_x, double ray_y, int f)
{
	int		i;
	int		add_temp;

	i = 0;
	while (i < h->scan->spr_c)
	{
		if (f == 0 && (h->sp_ar[i].x == (int)floor((ray_x) / SC) &&
		h->sp_ar[i].y == (int)floor((ray_y) / SC)))
		{
			add_temp = h->sp_ar[i].flag == 0 ? 1 : 0;
			h->sp_ar[i].flag = 1;
			h->im->sp_vis_count += add_temp;
			break ;
		}
		i++;
	}
}

void	set_sprite_flags(t_head *head)
{
	int		i;

	i = 0;
	while (i < head->scan->spr_c)
	{
		head->sp_ar[i].flag = 0;
		i++;
	}
}
