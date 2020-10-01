/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 23:24:35 by bshang            #+#    #+#             */
/*   Updated: 2020/07/24 16:18:02 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_l_n(unsigned long int n, int base)
{
	int		length;

	length = 0;
	while (n != 0)
	{
		n /= base;
		length++;
	}
	return (length);
}

static void	ft_calc(unsigned long int val, int base, char *ans, int *p)
{
	char	*arr;
	int		i;
	char	c;

	c = 'a';
	i = -1;
	if (val >= (unsigned long int)base)
		ft_calc(val / base, base, ans, p);
	arr = (char *)malloc(sizeof(char) * 17);
	while (++i < 10)
		arr[i] = i + '0';
	i--;
	while (++i < 16)
		arr[i] = c++;
	arr[i] = '\0';
	ans[(*p)++] = arr[val % base];
	free(arr);
}

char		*ft_itoa_base(unsigned long int value, int base)
{
	char	*ans;
	int		p;

	p = 0;
	if (base < 2 || base > 16 ||
		!(ans = (char *)malloc(sizeof(char) * ft_l_n(value, base) + 1)))
		return (NULL);
	ft_calc(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
