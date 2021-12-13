/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:59:17 by jabae             #+#    #+#             */
/*   Updated: 2021/12/08 17:16:15 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (unsigned char *)s;
	i = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)ptr + i);
	while (i)
	{
		i--;
		if (ptr[i] == (unsigned char)c)
			return ((char *)ptr + i);
	}
	return (NULL);
}
