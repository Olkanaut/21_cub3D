/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:35:07 by bshang            #+#    #+#             */
/*   Updated: 2020/05/09 17:24:24 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_d;
	const unsigned char	*ptr_s;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	ptr_d = (unsigned char*)dest;
	ptr_s = (unsigned char*)src;
	if (ptr_s < ptr_d)
		while (++i <= n)
			ptr_d[n - i] = ptr_s[n - i];
	else
		while (n-- > 0)
			*(ptr_d++) = *(ptr_s++);
	return (dest);
}
