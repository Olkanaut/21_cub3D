/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 18:23:07 by bshang            #+#    #+#             */
/*   Updated: 2020/09/16 13:22:57 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

int		cleaner(int fd, t_l **origin, char *buf, int res)
{
	t_l	*temp;
	t_l	*bin;

	free(buf);
	if (*origin)
	{
		temp = *origin;
		if (temp->fd == fd)
			*origin = temp->next;
		else
		{
			while (temp->next->fd != fd)
				temp = temp->next;
			bin = temp->next;
			temp->next = bin->next;
			temp = bin;
		}
		free(temp->rem);
		free(temp->rem_start);
		free(temp);
		temp = NULL;
	}
	return (res);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = 0;
	while (s[len] != '\0')
		len++;
	if (!(dup = (char*)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		++s;
	}
	if (c == '\0')
		return ((char*)s);
	return (0);
}

char	*ft_strjoin_free(char **s1, char *s2)
{
	size_t	i;
	size_t	len_sum;
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	i = 0;
	len_sum = ft_strlen(*s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (len_sum + 1))))
		return (NULL);
	len_sum = 0;
	while ((*s1)[i])
		str[len_sum++] = (*s1)[i++];
	i = 0;
	while (s2[i])
		str[len_sum++] = s2[i++];
	str[len_sum] = '\0';
	free(*s1);
	return (str);
}
