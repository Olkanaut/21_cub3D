/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:47:25 by bshang            #+#    #+#             */
/*   Updated: 2020/09/21 19:18:50 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

static double	calc_coordinates(t_head *h, int flag, int i, double k)
{
	if (flag == 1)
		return ((h->pl->pos[0] * h->im->plan_scale + h->im->plan_scale
		/ 2 + P_OFF * h->pl->pos[0]) + i * cos(to_rad(h->pl->dir -
		90 - FOV / 2 + k)));
	else if (flag == 2)
		return ((h->pl->pos[1] * h->im->plan_scale + h->im->plan_scale
		/ 2 + P_OFF * h->pl->pos[1]) + i * sin(to_rad(h->pl->dir -
		90 - FOV / 2 + k)));
	else if (flag == 3)
		return (h->pl->pos[0] * h->im->plan_scale + h->im->plan_scale / 2
		- 3 + P_OFF * h->pl->pos[0]);
	else
		return (h->pl->pos[1] * h->im->plan_scale + h->im->plan_scale / 2
		- 3 + P_OFF * h->pl->pos[1]);
}

static void		draw_rays_on_plan(t_head *h)
{
	double	k;
	int		i;
	double	r[2];

	k = 0;
	while (k < FOV)
	{
		i = 0;
		while (i < h->im->plan_size[0] * 0.05)
		{
			r[0] = calc_coordinates(h, 1, i, k);
			r[1] = calc_coordinates(h, 2, i, k);
			if (is_obj(h->map[(int)((r[1] - P_OFF * (r[1] / h->im->plan_scale -
			1)) / h->im->plan_scale)][(int)((r[0] - P_OFF * (r[0] /
			h->im->plan_scale - 1)) / h->im->plan_scale)]) == 0)
				break ;
			my_mlx_pixel_put(h->w_a, r[0], r[1], C5);
			i++;
		}
		k += FOV * 0.99;
	}
	r[0] = calc_coordinates(h, 3, i, k);
	r[1] = calc_coordinates(h, 4, i, k);
	put_sc_pxl(h, h->w_a, r, C6);
}

static void		draw_sprites_on_plan(t_head *h)
{
	int		k;
	double	t;
	double	p[2];

	t = 6.;
	k = h->scan->spr_c;
	while (k > 0)
	{
		p[0] = h->sp_ar[k - 1].x * h->im->plan_scale + P_OFF *
		h->sp_ar[k - 1].x + 0.5 * h->im->plan_scale * (1 - 1 / t);
		p[1] = h->sp_ar[k - 1].y * h->im->plan_scale + P_OFF *
		h->sp_ar[k - 1].y + 0.5 * h->im->plan_scale * (1 - 1 / t);
		put_sc_pxl(h, h->w_a, p, C3);
		k--;
	}
}

void			draw_plan(t_head *h)
{
	int		x;
	int		y;
	double	p[2];

	y = 0;
	p[1] = 0;
	while (p[1] < h->scan->map_size[1] * h->im->plan_scale)
	{
		x = 0;
		p[0] = 0;
		while (p[0] < h->scan->map_size[0] * h->im->plan_scale + P_OFF
		* (h->scan->map_size[0] - 1))
		{
			if (is_obj(h->map[y][x]) > 0)
				put_sc_pxl(h, h->w_a, p, C2);
			else
				put_sc_pxl(h, h->w_a, p, C1);
			p[0] += h->im->plan_scale + P_OFF;
			x++;
		}
		p[1] += h->im->plan_scale + P_OFF;
		y++;
	}
	draw_rays_on_plan(h);
	draw_sprites_on_plan(h);
}

int				draw_status(t_head *h, int flag)
{
	char	*str;

	if (!(str = ft_itoa(h->scan->spr_c)))
		return (ERR_MEM);
	if (!(str = ft_strjoin_free(&str, "  ")))
		return (ERR_MEM);
	if (flag == 1)
	{
		if (!(str = ft_strjoin_free(&str, "GHOSTS LEFT TO CATCH")))
			return (ERR_MEM);
	}
	else if (flag == 2)
	{
		if (!(str = ft_strjoin_free(&str, "DRINKS TO EMPTY")))
			return (ERR_MEM);
	}
	if (h->scan->spr_c != 0 && h->scan->res[1] > 15)
		mlx_string_put(h->w->mlx_ptr, h->w->win_ptr, h->scan->res[0] / 2,
		h->im->plan_size[1] / 20, C9, str);
	else if (h->scan->spr_c == 0 && h->scan->res[1] > 15)
		mlx_string_put(h->w->mlx_ptr, h->w->win_ptr, h->scan->res[0] / 2,
		h->scan->res[1] / 2, C9, "CONGRATS! YOU WON! :)");
	free(str);
	return (0);
}
