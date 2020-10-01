/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:38:51 by bshang            #+#    #+#             */
/*   Updated: 2020/05/22 11:02:18 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int i1;
	unsigned int i2;
	unsigned int res;

	if ((dest || src) && size != 0)
	{
		i1 = 0;
		i2 = 0;
		res = 0;
		while (dest[i2] && i2 < size)
			i2++;
		res = ft_strlen(src) + i2;
		if (size == i2)
			return (res);
		while (src[i1] && i2 + i1 < size - 1)
		{
			dest[i2 + i1] = src[i1];
			i1++;
		}
		dest[i2 + i1] = '\0';
		return (res);
	}
	return (ft_strlen(src));
}
