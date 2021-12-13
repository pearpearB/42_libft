/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:33:55 by jabae             #+#    #+#             */
/*   Updated: 2021/12/08 17:22:29 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp;
	size_t			i;

	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	if (!dst_tmp && !src_tmp)
		return (dst);
	if (dst_tmp > src_tmp)
	{
		i = len;
		while (i > 0)
		{
			dst_tmp[i - 1] = src_tmp[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst_tmp[i] = src_tmp[i];
			i++;
		}
	}
	return (dst);
}
