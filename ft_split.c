/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:41:44 by jabae             #+#    #+#             */
/*   Updated: 2021/12/13 19:01:32 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while ((s[i] != c) && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_seperator(char **ptr, char const *s, char c, size_t count)
{
	size_t	i;
	size_t	next;
	size_t	index;

	i = 0;
	index = 0;
	while (s[i] && index < count)
	{
		if (s[i] != c)
		{
			next = i + 1;
			while (s[next] && s[next] != c)
				next++;
			ptr[index] = ft_substr(s, i, next - i);
			if (!ptr[index])
				return (ft_free(ptr));
			index++;
			i = next;
		}
		else
			i++;
	}
	ptr[index] = (char *) '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	ptr = (char **)malloc(sizeof(char *) * word_count + 1);
	if (!ptr)
		return (NULL);
	ft_seperator(ptr, s, c, word_count);
	return (ptr);
}
