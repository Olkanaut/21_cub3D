/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:39:59 by bshang            #+#    #+#             */
/*   Updated: 2020/05/03 11:40:00 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = (0);
	while (*s)
	{
		if (*s == c)
			temp = (char*)s;
		++s;
	}
	if (c == '\0')
		return ((char*)s);
	if (temp)
		return (temp);
	return (0);
}
