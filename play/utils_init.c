/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 21:34:13 by bshang            #+#    #+#             */
/*   Updated: 2020/09/21 19:56:07 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

int		init_images_and_put_to_win_and_clear(t_head *h, int flag)
{
	if (flag == 1)
	{
		if (!(h->w_a->img = mlx_new_image(h->w->mlx_ptr, h->scan->res[0],
		h->scan->res[1])))
			return (ERR_MEM);
		if (!(h->w_a->data = mlx_get_data_addr(h->w_a->img, &h->w_a->bpp,
		&h->w_a->llen, &h->w_a->endian)))
			return (ERR_MEM);
		if (!(h->w_p->img = mlx_new_image(h->w->mlx_ptr, h->im->plan_size[0],
		h->im->plan_size[1])))
			return (ERR_MEM);
		if (!(h->w_p->data = mlx_get_data_addr(h->w_p->img, &h->w_p->bpp,
		&h->w_p->llen, &h->w_p->endian)))
			return (ERR_MEM);
	}
	else
		mlx_put_image_to_window(h->w->mlx_ptr, h->w->win_ptr, h->w_a->img,
		0, 0);
	return (0);
}

int		init_textures(t_head *h)
{
	if (!(h->txtr->no = set_textures(h, h->txtr->no, h->scan->path_no)))
		return (ERR_MEM);
	if (!(h->txtr->ea = set_textures(h, h->txtr->ea, h->scan->path_ea)))
		return (ERR_MEM);
	if (!(h->txtr->so = set_textures(h, h->txtr->so, h->scan->path_so)))
		return (ERR_MEM);
	if (!(h->txtr->we = set_textures(h, h->txtr->we, h->scan->path_we)))
		return (ERR_MEM);
	if (!(h->txtr->sp1 = set_textures(h, h->txtr->sp1, h->scan->sprite)))
		return (ERR_MEM);
	if (h->scan->bonus_f > 0)
		if (init_bonus_textures(h) < 0)
			return (ERR_MEM);
	set_colors(h);
	return (0);
}

int		init_window(t_head *h)
{
	int		x;
	int		y;

	if (!(h->w->mlx_ptr = mlx_init()))
		return (ERR_MEM);
	mlx_get_screen_size(h->w->mlx_ptr, &x, &y);
	if (x < h->scan->res[0])
		h->scan->res[0] = x;
	if (y < h->scan->res[1])
		h->scan->res[1] = y;
	if (h->scan->bonus_f > 0)
		define_plan_size(h);
	if (!(h->w->win_ptr = mlx_new_window(h->w->mlx_ptr, h->scan->res[0],
	h->scan->res[1], "cubelolo")))
		return (ERR_MEM);
	return (0);
}

void	clear_images(t_head *h)
{
	mlx_destroy_image(h->w->mlx_ptr, h->w_a->img);
	mlx_destroy_image(h->w->mlx_ptr, h->w_p->img);
}
