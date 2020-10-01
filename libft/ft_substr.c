/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 17:36:46 by bshang            #+#    #+#             */
/*   Updated: 2020/05/21 00:04:44 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	unsigned int		i;
	unsigned int		len_total;
	unsigned int		sub_len;

	if (!s)
		return (NULL);
	len_total = ft_strlen(s);
	if (start > len_total)
		return (ft_strdup(""));
	if (start + len > len_total)
		sub_len = len_total - start;
	else
		sub_len = len;
	if (!(substr = (char*)malloc(sizeof(char) * (sub_len + 1))))
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
