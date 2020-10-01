/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:47:30 by bshang            #+#    #+#             */
/*   Updated: 2020/09/18 11:24:47 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

void		rotate_event(t_head *h, int key)
{
	if (key == 12 || key == 123)
	{
		h->pl->dir -= STEP_ROT;
		if (h->pl->dir <= 0.)
			h->pl->dir += 360.0;
	}
	else if (key == 14 || key == 124)
	{
		h->pl->dir += STEP_ROT;
		if (h->pl->dir > 360.)
			h->pl->dir -= 360.0;
	}
}

static void	move_north_or_south(t_head *h, int key)
{
	if (key == 13 || key == 126)
	{
		if ((is_obj(h->map[(int)(h->pl->pos[1] + 0.5)][(int)
		((h->pl->pos[0] + 0.5) + STEP_MOVE * sin(to_rad(h->pl->dir)))]) > 0))
			h->pl->pos[0] += STEP_MOVE * sin(to_rad(h->pl->dir));
		if ((is_obj(h->map[(int)((h->pl->pos[1] + 0.5) - STEP_MOVE *
		cos(to_rad(h->pl->dir)))][(int)(h->pl->pos[0] + 0.5)]) > 0))
			h->pl->pos[1] -= STEP_MOVE * cos(to_rad(h->pl->dir));
	}
	else if (key == 1 || key == 125)
	{
		if ((is_obj(h->map[(int)(h->pl->pos[1] + 0.5)][(int)
		((h->pl->pos[0] + 0.5) - STEP_MOVE * sin(to_rad(h->pl->dir)))]) > 0))
			h->pl->pos[0] -= STEP_MOVE * sin(to_rad(h->pl->dir));
		if ((is_obj(h->map[(int)((h->pl->pos[1] + 0.5) +
		STEP_MOVE * cos(to_rad(h->pl->dir)))][(int)(h->pl->pos[0] + 0.5)]) > 0))
			h->pl->pos[1] += STEP_MOVE * cos(to_rad(h->pl->dir));
	}
}

static void	move_east_or_west(t_head *h, int key)
{
	if (key == 2)
	{
		if ((is_obj(h->map[(int)(h->pl->pos[1] + 0.5)][(int)
		((h->pl->pos[0] + 0.5) + STEP_MOVE * cos(to_rad(h->pl->dir)))]) > 0))
			h->pl->pos[0] += STEP_MOVE * cos(to_rad(h->pl->dir));
		if ((is_obj(h->map[(int)((h->pl->pos[1] + 0.5) +
		STEP_MOVE * sin(to_rad(h->pl->dir)))][(int)(h->pl->pos[0] + 0.5)]) > 0))
			h->pl->pos[1] += STEP_MOVE * sin(to_rad(h->pl->dir));
	}
	else if (key == 0)
	{
		if ((is_obj(h->map[(int)(h->pl->pos[1] + 0.5)][(int)
		((h->pl->pos[0] + 0.5) - STEP_MOVE * cos(to_rad(h->pl->dir)))]) > 0))
			h->pl->pos[0] -= STEP_MOVE * cos(to_rad(h->pl->dir));
		if ((is_obj(h->map[(int)((h->pl->pos[1] + 0.5) -
		STEP_MOVE * sin(to_rad(h->pl->dir)))][(int)(h->pl->pos[0] + 0.5)]) > 0))
			h->pl->pos[1] -= STEP_MOVE * sin(to_rad(h->pl->dir));
	}
}

void		move_event(t_head *h, int key)
{
	if (key == 13 || key == 126)
		move_north_or_south(h, key);
	else if (key == 2)
		move_east_or_west(h, key);
	else if (key == 1 || key == 125)
		move_north_or_south(h, key);
	else if (key == 0)
		move_east_or_west(h, key);
}
