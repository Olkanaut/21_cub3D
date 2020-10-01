/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 20:55:52 by bshang            #+#    #+#             */
/*   Updated: 2020/09/21 19:20:11 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

static void	sort_sprites(t_head *h)
{
	int			i;
	int			j;
	t_sprite	*temp;

	temp = &(t_sprite){0, 0, 0, 0, 0, 0};
	set_sprite_distances(h);
	j = 0;
	while (j < h->scan->spr_c)
	{
		i = 0;
		while (i < h->scan->spr_c - j - 1)
		{
			if (h->sp_ar[i].dist < h->sp_ar[i + 1].dist)
			{
				*temp = h->sp_ar[i];
				h->sp_ar[i] = h->sp_ar[i + 1];
				h->sp_ar[i + 1] = *temp;
			}
			i++;
		}
		j++;
	}
}

static void	calc_sprite_fields(t_head *h, int i)
{
	h->sp_ar[i].dist = calc_d(h->sp_ar[i].x * SC - SC / 2,
	h->pl->pos[0] * SC - SC / 2, h->sp_ar[i].y * SC - SC / 2,
	h->pl->pos[1] * SC - SC / 2);
	h->sp_ar[i].h = SPRITE_SIZE_COEF * h->scan->res[1] / (2 *
	tan(to_rad(FOV_V / 2))) * WALL_HEIGHT / h->sp_ar[i].dist;
	h->sp_ar[i].w = h->sp_ar[i].h * h->txtr->sp1->img_width
	/ h->txtr->sp1->img_height;
}

static void	draw_one_sprite(t_head *h, double j, int i)
{
	double		x;
	double		y;
	double		y0;

	calc_sprite_fields(h, i);
	x = ceil(j - h->sp_ar[i].w / 2);
	while (x < h->scan->res[0] && x < j + h->sp_ar[i].w / 2 && j +
	(h->sp_ar[i].w / 2) > 0)
	{
		y = (h->scan->res[1] - h->sp_ar[i].h) / 2;
		if (h->arr_v_dist[(int)x] > h->sp_ar[i].dist)
		{
			while (y < h->scan->res[1] / 2 + h->sp_ar[i].h / 2)
			{
				y0 = (y - ((h->scan->res[1] - h->sp_ar[i].h) / 2)) *
				h->txtr->sp1->img_height / h->sp_ar[i].h;
				get_color(h->txtr->sp1, (x - (j - h->sp_ar[i].w / 2)) *
				h->txtr->sp1->img_height / h->sp_ar[i].h, y0, &h->temp_color);
				if (h->temp_color != 0xff00ff && y > 0 && y < h->scan->res[1])
					my_mlx_pixel_put(h->w_a, x, y, h->temp_color);
				y++;
			}
		}
		x++;
	}
}

void		draw_sprites(t_head *h)
{
	int			i;
	double		s_angle;
	double		j;

	sort_sprites(h);
	i = 0;
	while (i < h->scan->spr_c)
	{
		if (h->sp_ar[i].flag == 1)
		{
			s_angle = (180.0 / M_PI) * atan2(h->sp_ar[i].y - h->pl->pos[1],
			h->sp_ar[i].x - h->pl->pos[0]);
			s_angle -= h->pl->dir - FOV / 2 + 90.0;
			while (s_angle < 0.)
				s_angle += 360.0;
			while (s_angle >= 360.0)
				s_angle -= 360.0;
			if (s_angle >= FOV)
				s_angle -= 180.;
			j = s_angle * h->scan->res[0] / FOV;
			draw_one_sprite(h, j, i);
		}
		i++;
	}
}
