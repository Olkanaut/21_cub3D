/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_obstacle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:38:53 by bshang            #+#    #+#             */
/*   Updated: 2020/09/18 12:11:14 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

static double	calc_quadr_one(t_head *h, double angle)
{
	double	dx1;
	double	dx2;

	dx1 = fabs((floor(h->obst->x0 / SC) + 1) * SC - h->obst->x0);
	dx2 = fabs((floor(h->obst->y0 / SC)) * SC - h->obst->y0) / tan(to_rad(90
	- angle));
	if (dx1 < dx2)
	{
		h->obst->x_txtr = (((int)(h->obst->y0 - dx1 * tan(to_rad(90 - angle)))
		% (int)SC) * h->txtr->ea->img_width) / SC;
		h->obst->x0 = (floor(h->obst->x0 / SC) + 1) * SC + 1;
		h->obst->y0 = h->obst->y0 - dx1 * tan(to_rad(90 - angle));
		h->obst->side = 'e';
	}
	else
	{
		h->obst->x_txtr = (((int)(h->obst->x0 + dx2) % (int)SC) *
		h->txtr->no->img_width) / SC;
		h->obst->x0 = h->obst->x0 + dx2;
		h->obst->y0 = (floor(h->obst->y0 / SC)) * SC - 1;
		h->obst->side = 'n';
	}
	return (calc_d(h->obst->x0, h->pl->pos[0] * SC + SC / 2,
	h->obst->y0, h->pl->pos[1] * SC + SC / 2));
}

static double	calc_quadr_two(t_head *h, double angle)
{
	double	dx1;
	double	dx2;

	dx1 = fabs(floor(h->obst->x0 / SC + 1) * SC - h->obst->x0);
	dx2 = fabs(tan(to_rad(180 - angle)) * fabs(floor(h->obst->y0 /
	SC + 1) * SC - h->obst->y0));
	if (dx1 < dx2)
	{
		h->obst->x_txtr = (((int)(h->obst->y0 + fabs(dx1 /
		tan(to_rad(180 - angle)))) % (int)SC) * h->txtr->ea->img_width) / SC;
		h->obst->x0 = floor(h->obst->x0 / SC + 1) * SC + 1;
		h->obst->y0 = h->obst->y0 + fabs(dx1 / tan(to_rad(180 - angle)));
		h->obst->side = 'e';
	}
	else
	{
		h->obst->x_txtr = ((SC - (int)(h->obst->x0 + dx2) %
		(int)SC) * h->txtr->so->img_width) / SC;
		h->obst->x0 = h->obst->x0 + dx2;
		h->obst->y0 = floor(h->obst->y0 / SC + 1) * SC + 1;
		h->obst->side = 's';
	}
	return (calc_d(h->obst->x0, h->pl->pos[0] * SC +
	SC / 2, h->obst->y0, h->pl->pos[1] * SC + SC / 2));
}

static double	calc_quadr_three(t_head *h, double angle)
{
	double	dx1;
	double	dx2;

	dx1 = fabs(floor(h->obst->x0 / SC) * SC - h->obst->x0);
	dx2 = fabs(tan(to_rad(angle - 180)) * fabs(floor(h->obst->y0 / SC + 1) *
	SC - h->obst->y0));
	if (dx1 < dx2)
	{
		h->obst->x_txtr = ((SC - (int)(h->obst->y0 + fabs(dx1 /
		tan(to_rad(angle - 180)))) % (int)SC) * h->txtr->we->img_width) / SC;
		h->obst->x0 = floor(h->obst->x0 / SC) * SC - 1;
		h->obst->y0 = h->obst->y0 + fabs(dx1 / tan(to_rad(angle - 180)));
		h->obst->side = 'w';
	}
	else
	{
		h->obst->x_txtr = ((SC - (int)(h->obst->x0 - dx2) % (int)SC)
		* h->txtr->so->img_width) / SC;
		h->obst->x0 = h->obst->x0 - dx2;
		h->obst->y0 = floor(h->obst->y0 / SC + 1) * SC + 1;
		h->obst->side = 's';
	}
	return (calc_d(h->obst->x0, h->pl->pos[0] * SC + SC / 2,
	h->obst->y0, h->pl->pos[1] * SC + SC / 2));
}

static double	calc_quadr_four(t_head *h, double angle)
{
	double	dx1;
	double	dx2;

	dx1 = fabs(floor(h->obst->x0 / SC) * SC - h->obst->x0);
	dx2 = tan(to_rad(360 - angle)) * fabs(floor(h->obst->y0 / SC)
	* SC - h->obst->y0);
	if (dx1 < dx2)
	{
		h->obst->x_txtr = ((SC - (int)(h->obst->y0 - dx1 *
		tan(to_rad(angle - 270))) % (int)SC) * h->txtr->we->img_width) / SC;
		h->obst->x0 = floor(h->obst->x0 / SC) * SC - 1;
		h->obst->y0 = h->obst->y0 - dx1 * tan(to_rad(angle - 270));
		h->obst->side = 'w';
	}
	else
	{
		h->obst->x_txtr = (((int)(h->obst->x0 - dx2) % (int)SC) *
		h->txtr->no->img_width) / SC;
		h->obst->x0 = h->obst->x0 - dx2;
		h->obst->y0 = floor(h->obst->y0 / SC) * SC - 1;
		h->obst->side = 'n';
	}
	return (calc_d(h->obst->x0, h->pl->pos[0] * SC + SC / 2,
	h->obst->y0, h->pl->pos[1] * SC + SC / 2));
}

void			calc_dist_to_wall(t_head *h, double angle)
{
	int		i;

	angle = norm_angle(angle);
	calc_obst_coord(h);
	i = 0;
	while (i < RAY_FARTHEST_POINT)
	{
		if (angle >= 0 && angle < 90)
			h->im->dist = calc_quadr_one(h, angle);
		else if (angle >= 90 && angle < 180)
			h->im->dist = calc_quadr_two(h, angle);
		else if (angle >= 180 && angle < 270)
			h->im->dist = calc_quadr_three(h, angle);
		else if (angle >= 270 && angle < 360)
			h->im->dist = calc_quadr_four(h, angle);
		if (is_obj(h->map[(int)(h->pl->pos[1] + 0.5)][(int)(h->pl->pos[0]
		+ 0.5)]) == 2)
			eat_spr(h, (int)(h->pl->pos[0] + 0.5), (int)(h->pl->pos[1] + 0.5));
		if (is_obj(h->map[(int)floor(h->obst->y0 / SC)][(int)floor(h->obst->x0
		/ SC)]) == 2)
			define_spr_and_fill(h, h->obst->x0, h->obst->y0, 0);
		if (is_obj(h->map[(int)floor(h->obst->y0 / SC)][(int)floor(h->obst->x0
		/ SC)]) == 0)
			break ;
	}
}
