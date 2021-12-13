/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:15:07 by jabae             #+#    #+#             */
/*   Updated: 2021/12/08 17:01:14 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*find_ptr;
	size_t			i;
	size_t			j;

	find_ptr = needle;
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = i;
		while (haystack[j] == *find_ptr && j < len)
		{
			j++;
			find_ptr++;
			if (*find_ptr == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
