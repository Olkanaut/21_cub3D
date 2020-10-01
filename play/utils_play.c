/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 21:32:34 by bshang            #+#    #+#             */
/*   Updated: 2020/09/18 14:29:37 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

void	my_mlx_pixel_put(t_w *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->llen + x * (data->bpp / 8));
	*(UI*)dst = color;
}

double	calc_d(double x1, double x2, double y1, double y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}

void	calc_obst_coord(t_head *h)
{
	h->obst->x0 = h->pl->pos[0] * SC + SC / 2;
	h->obst->y0 = h->pl->pos[1] * SC + SC / 2;
}

double	norm_angle(double angle)
{
	while (angle < 0)
		angle += 360.0;
	while (angle >= 360)
		angle -= 360.0;
	return (angle);
}

int		save_screenshot(t_head *head)
{
	char	*bmp;
	int		fd;
	int		size;

	size = head->scan->res[0] * head->scan->res[1] * (head->w_a->bpp >> 3) + 54;
	if (!(bmp = (char*)malloc(sizeof(char) * size)))
		return (ERR_MEM);
	ft_bzero(bmp, size);
	ft_memcpy(&bmp[0], "BM", 2);
	fd = 54;
	ft_memcpy(&bmp[10], &fd, 4);
	fd = 40;
	ft_memcpy(&bmp[14], &fd, 4);
	ft_memcpy(&bmp[18], &head->scan->res[0], 4);
	fd = -head->scan->res[1];
	ft_memcpy(&bmp[22], &fd, 4);
	fd = 1;
	ft_memcpy(&bmp[26], &fd, 2);
	ft_memcpy(&bmp[28], &head->w_a->bpp, 2);
	ft_memcpy(&bmp[54], head->w_a->data, size - 54);
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	fd = write(fd, bmp, size);
	free(bmp);
	close(fd);
	return (0);
}
