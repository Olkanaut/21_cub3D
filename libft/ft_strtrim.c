/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:40:23 by bshang            #+#    #+#             */
/*   Updated: 2020/05/21 09:46:41 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char const	*fin;
	char		*res;

	if (!s)
		return (NULL);
	while (ft_strchr(set, *s) && *s)
		s++;
	fin = s;
	while (*fin)
		fin++;
	while (ft_strchr(set, *fin) && (fin - s))
		fin--;
	res = ft_substr(s, 0, fin - s + 1);
	return (res);
}
