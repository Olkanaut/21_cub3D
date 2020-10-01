/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:38:46 by bshang            #+#    #+#             */
/*   Updated: 2020/05/15 17:21:14 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i1;
	int		i2;
	int		len_sum;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len_sum = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!(str = (char*)malloc(sizeof(char) * (len_sum) + 1)))
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (i1 < len_sum)
	{
		if (i1 < (int)ft_strlen((char*)s1))
			str[i1] = s1[i1];
		else
			str[i1] = s2[i2++];
		i1++;
	}
	str[i1] = '\0';
	return (str);
}
