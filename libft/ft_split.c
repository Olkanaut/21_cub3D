/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:40:04 by bshang            #+#    #+#             */
/*   Updated: 2020/05/22 19:55:29 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_updated(char *s, int *i, char c)
{
	int		len;

	len = 0;
	while (s[*i] && s[(*i)++] != c)
		len++;
	return (len);
}

static int	tok_num(char *s, char c)
{
	int		i;
	int		token_number;

	i = 0;
	token_number = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			token_number++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (token_number);
}

static char	**free_array(char **arr)
{
	int		i;

	i = 0;
	while (*arr)
		free(arr[i++]);
	free(arr);
	return (arr);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	char	**res;
	int		i;
	int		start;
	int		new_length;

	i = 0;
	if ((!s) || !(res = (char**)ft_calloc(tok_num((char*)s, c) + 1, sizeof(s))))
		return (NULL);
	arr = res;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
			continue;
		}
		start = i;
		new_length = len_updated((char *)s, &i, c);
		if (!(*res = ft_calloc(new_length + 1, sizeof(char))))
			return (free_array(arr));
		*res = ft_memcpy(*res, &s[start], new_length);
		res++;
	}
	return (arr);
}
