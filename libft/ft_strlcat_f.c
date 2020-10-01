/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:38:51 by bshang            #+#    #+#             */
/*   Updated: 2020/05/20 22:32:05 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i1;
	size_t	i2;
	size_t	res;

	i1 = 0;
	i2 = 0;
	res = 0;
	while (dest[i1] != '\0')
		i1++;
	while (src[res] != '\0')
		res++;
	if (i1 >= size)
		res = res + size;
	else
		res = res + i1;
	while (src[i2] != '\0' && i1 + 1 < size)
	{
		dest[i1] = src[i2];
		i1++;
		i2++;
	}
	dest[i1] = '\0';
	return (res);
}
