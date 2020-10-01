/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:35:39 by bshang            #+#    #+#             */
/*   Updated: 2020/05/03 13:10:27 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putchar_fd('1', fd);
		ft_putnbr_fd(47483648, fd);
		return ;
	}
	if (n < 0 && n > -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd((-1 * n), fd);
	}
	else if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else if (n <= 2147483647)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
