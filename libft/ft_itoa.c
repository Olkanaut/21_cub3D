/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:33:47 by bshang            #+#    #+#             */
/*   Updated: 2020/05/17 21:37:14 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int nbr)
{
	int		len;

	len = 0;
	while (nbr <= -10 || nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	if (nbr < 0)
		len++;
	return (len);
}

static char	*ft_write_to_str(int nbr, char *str, int x, int len)
{
	if (x < 0)
		str[0] = '-';
	str[len + 1] = '\0';
	while (len >= 0)
	{
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
		if (len == 0 && x < 0)
			break ;
	}
	return (str);
}

char		*ft_itoa(int nbr)
{
	int		len;
	int		sign;
	char	*str;

	len = 0;
	sign = 1;
	len = ft_num_len(nbr);
	if (!(str = (char*)malloc(sizeof(*str) * (len + 2))))
		return (NULL);
	if (nbr == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		sign *= (-1);
	}
	str = ft_write_to_str(nbr, str, sign, len);
	return (str);
}
