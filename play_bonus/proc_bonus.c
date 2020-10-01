/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:41:48 by bshang            #+#    #+#             */
/*   Updated: 2020/09/21 22:24:07 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

int		init_bonus_textures(t_head *h)
{
	if (!(h->txtr->arm = set_textures(h, h->txtr->arm, PATH_ARMS)))
		return (ERR_MEM);
	if (!(h->txtr->sky = set_textures(h, h->txtr->sky, PATH_SKY)))
		return (ERR_MEM);
	return (0);
}

int		close_event(void *var)
{
	t_w		*vars;

	vars = (t_w *)var;
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	// system("killall afplay");
	exit(0);
	return ('a');
}

int		proc_event(int key, void *ptr)
{
	t_head	*h;

	h = (t_head*)ptr;
	mlx_clear_window(h->w->mlx_ptr, h->w->win_ptr);
	move_event(h, key);
	rotate_event(h, key);
	if (key == 53)
		close_event(h->w);
	clear_images(h);
	draw_window(h);
	return (0);
}

int		draw_window(t_head *head)
{
	head->im->sp_vis_count = 0;
	if (init_images_and_put_to_win_and_clear(head, 1) < 0)
		return (ERR_MEM);
	if (init_textures(head) < 0)
		return (ERR_MEM);
	draw_axo(head);
	draw_sprites(head);
	if (head->scan->bonus_f == 1)
	{
		draw_plan(head);
		if (head->scan->spr_c != 0)
			draw_arms(head);
	}
	init_images_and_put_to_win_and_clear(head, 2);
	if (draw_status(head, 1) < 0)
		return (ERR_MEM);
	if (head->scan->save_f == 1)
	{
		if (save_screenshot(head) < 0)
			return (ERR_MEM);
		mlx_clear_window(head->w->mlx_ptr, head->w->win_ptr);
		mlx_destroy_window(head->w->mlx_ptr, head->w->win_ptr);
		exit(0);
	}
	return (0);
}

int		play(t_head *h)
{
	// if (h->scan->bonus_f == 1 && h->scan->save_f != 1)
	// 	system(PATH_MUS);
	h->w = &(t_w){(V*)0, (V*)0, (V*)0, (V*)0, 0, 0, 0, {0, 0}};
	h->w_a = &(t_w){(V*)0, (V*)0, (V*)0, (V*)0, 0, 0, 0, {0, 0}};
	h->w_p = &(t_w){(V*)0, (V*)0, (V*)0, (V*)0, 0, 0, 0, {0, 0}};
	h->txtr = &(t_txtr){(V*)0, (V*)0, (V*)0, (V*)0, (V*)0, (V*)0, (V*)0, 0, 0};
	h->im = &(t_image){0, 0, 0, 0, 0, 0, {0, 0}};
	h->obst = &(t_obstacle){0, 0, 0, 0, 0, 0, 0};
	h->txtr->no = &(t_t){(V*)0, (V*)0, (V*)0, (V*)0, 0, 0, 0, 0, 0};
	h->txtr->ea = &(t_t){(V*)0, (V*)0, (V*)0, (V*)0, 0, 0, 0, 0, 0};
	h->txtr->so = &(t_t){(V*)0, (V*)0, (V*)0, (V*)0, 0, 0, 0, 0, 0};
	h->txtr->we = &(t_t){(V*)0, (V*)0, (V*)0, (V*)0, 0, 0, 0, 0, 0};
	h->txtr->sp1 = &(t_t){(V*)0, (V*)0, (V*)0, (V*)0, 0, 0, 0, 0, 0};
	h->txtr->arm = &(t_t){(V*)0, (V*)0, (V*)0, (V*)0, 0, 0, 0, 0, 0};
	h->txtr->sky = &(t_t){(V*)0, (V*)0, (V*)0, (V*)0, 0, 0, 0, 0, 0};
	if (!(h->arr_v_dist = (double *)malloc(sizeof(double) * h->scan->res[0])))
		return (ERR_MEM);
	if (init_window(h) < 0)
		return (ERR_MEM);
	if (draw_window(h) < 0)
		return (ERR_MEM);
	mlx_hook(h->w->win_ptr, 2, 1L, proc_event, h);
	mlx_hook(h->w->win_ptr, 17, 0L, close_event, h->w);
	mlx_loop(h->w->mlx_ptr);
	return (0);
}
