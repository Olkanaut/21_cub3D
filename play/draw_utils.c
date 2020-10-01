/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:20:02 by bshang            #+#    #+#             */
/*   Updated: 2020/10/01 18:20:52 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

void	put_sc_pxl(t_head *h, void *ptr, double p[2], UI color)
{
	int		i;
	int		j;
	double	sc;

	sc = (color == C6 || color == C3 || color == C12) ? 6 : h->im->plan_scale;
	i = p[1];
	while (i < p[1] + sc)
	{
		j = p[0];
		while (j < p[0] + sc)
		{
			my_mlx_pixel_put(ptr, j, i, color);
			j++;
		}
		i++;
	}
}

t_t		*set_textures(t_head *h, t_t *s, char *path)
{
	if (!(s->img = mlx_xpm_file_to_image(h->w->mlx_ptr, path, &s->img_width,
	&s->img_height)))
		return (NULL);
	if (!(s->data = mlx_get_data_addr(s->img, &s->bpp, &s->llen,
	&s->endian)))
		return (NULL);
	return (s);
}

void	fill_color(t_head *h, double j, double i, int flag)
{
	if (flag == 0)
		my_mlx_pixel_put(h->w_a, (int)floor(j), (int)floor(i), create_trgb(0,
		h->scan->ceiling[0], h->scan->ceiling[1], h->scan->ceiling[2]));
	else if (flag == 3)
		my_mlx_pixel_put(h->w_a, (int)floor(j), (int)floor(i), C8);
	else
		my_mlx_pixel_put(h->w_a, (int)floor(j), (int)floor(i), create_trgb(0,
		h->scan->floor[0], h->scan->floor[1], h->scan->floor[2]));
}

void	define_plan_size(t_head *h)
{
	h->im->plan_size[1] = h->scan->res[1] / 4;
	h->im->plan_scale = (int)floor(((h->scan->res[1] / 4) - P_OFF *
	(h->scan->map_size[1] - 1)) / h->scan->map_size[1]);
	h->im->plan_size[0] = h->scan->map_size[0] * h->im->plan_scale +
	P_OFF * (h->scan->map_size[0] - 1);
	if (h->im->plan_size[0] > h->scan->res[0] / 2)
	{
		h->im->plan_size[0] = h->scan->res[0] / 2 - 10;
		h->im->plan_scale = (h->im->plan_size[0] - P_OFF *
		(h->scan->map_size[0] - 1)) / h->scan->map_size[0];
		h->im->plan_size[1] = h->scan->map_size[1] * h->im->plan_scale +
		P_OFF * (h->scan->map_size[1] - 1);
		h->im->plan_size[0] = h->im->plan_scale * h->scan->map_size[0] +
		P_OFF * (h->scan->map_size[0] - 1);
	}
}
