/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:03:34 by bshang            #+#    #+#             */
/*   Updated: 2020/09/17 21:49:51 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

int		main(int argc, char **argv)
{
	t_head	head;
	int		t;

	head.pl = &(t_player){{0, 0}, 0, 0};
	t = scan_file(argc, argv, &head);
	if (t < 0)
		print_error(t);
	head.scan->bonus_f = 0;
	t = play(&head);
	if (t < 0)
		print_error(t);
	exit(0);
}
