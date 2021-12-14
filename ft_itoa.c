/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:57:17 by jabae             #+#    #+#             */
/*   Updated: 2021/12/14 11:00:23 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_n_len(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	n_len;

	n_len = ft_n_len(n);
	str = (char *)malloc(sizeof(char) * n_len + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
	}
	str[n_len] = '\0';
	while (n)
	{
		str[n_len - 1] = ft_abs(n % 10) + 48;
		n /= 10;
		n_len--;
	}
	return (str);
}
