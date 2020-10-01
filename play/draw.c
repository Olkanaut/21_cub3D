/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 11:22:24 by bshang            #+#    #+#             */
/*   Updated: 2020/09/18 15:58:29 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

void	draw_arms(t_head *h)
{
	double	x;
	double	y;
	double	xt;
	double	yt;
	double	g_size_x;

	g_size_x = GUN_SIZE * h->scan->res[1] * h->txtr->arm->img_width
	/ h->txtr->arm->img_height;
	g_size_x = g_size_x > h->scan->res[0] / 2 ? h->scan->res[0] / 2 : g_size_x;
	y = h->scan->res[1] * (1 - GUN_SIZE);
	while (y < h->scan->res[1])
	{
		x = h->scan->res[0] / 2;
		while (x + g_size_x > (h->scan->res[0] / 2))
		{
			xt = h->txtr->arm->img_width * (h->scan->res[0] / 2 - x) / g_size_x;
			yt = ((y - h->scan->res[1] * (1 - GUN_SIZE)) / (GUN_SIZE *
			h->scan->res[1])) * h->txtr->arm->img_height;
			get_color(h->txtr->arm, xt, yt, &h->temp_color);
			if (h->temp_color != 0xff00ff)
				my_mlx_pixel_put(h->w_a, x, y, h->temp_color);
			x--;
		}
		y++;
	}
}

void	draw_txtr_pixel_sky(t_head *h, double i, double angle)
{
	while (angle >= 360.)
		angle -= 360.;
	while (angle < 0.)
		angle += 360.;
	get_color(h->txtr->sky, angle / 90. * h->txtr->sky->img_width,
	h->txtr->sky->img_height / (h->scan->res[1] * 0.96) * i, &h->obst->color);
	my_mlx_pixel_put(h->w_a, h->im->j, i, h->obst->color);
}

void	draw_txtr_pxl(t_head *h, double i, double y_range, double y1)
{
	double		x0;
	double		y0;

	get_txtr_details(h, 1, 0, 0);
	x0 = h->obst->x_txtr - 0.1;
	y0 = (i - y1) * h->obst->img_height / y_range;
	get_txtr_details(h, 0, x0, y0);
	my_mlx_pixel_put(h->w_a, h->im->j, i, h->obst->color);
}

void	draw_vert(t_head *head, double angle)
{
	double	d;
	double	h_wall;
	double	y1;
	double	y2;
	double	i;

	d = head->scan->res[1] / (2 * tan(to_rad(FOV_V / 2)));
	h_wall = d * WALL_HEIGHT / (head->im->dist * cos(to_rad(head->pl->dir
	- angle)));
	y1 = (head->scan->res[1] - h_wall) / 2;
	y2 = y1 + h_wall;
	i = 0;
	while (i < head->scan->res[1])
	{
		if (i < y1)
			head->scan->bonus_f > 0 ? draw_txtr_pixel_sky(head,
			i, angle) : fill_color(head, head->im->j, i, 0);
		if (i >= y1 && i <= y2)
			draw_txtr_pxl(head, i, y2 - y1, ceil(y1));
		if (i > y2)
			fill_color(head, head->im->j, i, 3);
		i++;
	}
}

void	draw_axo(t_head *head)
{
	double		k;
	double		angle;
	int			i;

	set_sprite_flags(head);
	k = 0;
	i = 0;
	while (k < FOV)
	{
		angle = head->pl->dir - FOV / 2 + k;
		calc_dist_to_wall(head, angle);
		head->im->j = i;
		draw_vert(head, angle);
		head->arr_v_dist[i] = head->im->dist;
		k += FOV / head->scan->res[0];
		i++;
	}
}
