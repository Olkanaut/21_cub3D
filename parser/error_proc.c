/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:29:31 by bshang            #+#    #+#             */
/*   Updated: 2020/09/18 11:53:32 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

int		finalize(int fd, int res)
{
	close(fd);
	return (res);
}

void	print_error(int res)
{
	if (res == 0)
		ft_putstr_fd("Correct\n", 2);
	if (res == -1)
		ft_putstr_fd("Error -1\n", 2);
	else if (res == 2)
		ft_putstr_fd("Error while processing\n", 2);
	if (res == -2)
		ft_putstr_fd("Error in a field\n", 2);
	else if (res == -3)
		ft_putstr_fd("Error while allocating memory\n", 2);
	else if (res == -4)
		ft_putstr_fd("Error while opening\n", 2);
	else if (res == -5)
		ft_putstr_fd("Error with arguments\n", 2);
	else if (res == -6)
		ft_putstr_fd("Error while processing file\n", 2);
	exit(0);
}
