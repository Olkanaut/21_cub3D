/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:34:30 by bshang            #+#    #+#             */
/*   Updated: 2020/05/09 17:17:21 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;
	size_t			i;

	ptr_d = (unsigned char*)dest;
	ptr_s = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ptr_d[i] = ptr_s[i];
		if (ptr_d[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		i++;
	}
	return (NULL);
}
