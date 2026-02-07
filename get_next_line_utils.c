/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:48:54 by ebin-ahm          #+#    #+#             */
/*   Updated: 2026/02/07 19:45:22 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	index1;
	size_t	index2;
	char	*out;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	out = (char *)malloc(len1 + len2 + 1);
	if (!out)
		return (NULL);
	index1 = 0;
	while (s1 && index1 < len1)
	{
		out[index1] = s1[index1];
		index1++;
	}
	index2 = 0;
	while (s2 && index2 < len2)
	{
		out[index1 + index2] = s2[index2];
		index2++;
	}
	out[index1 + index2] = '\0';
	return (out);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	index;
	char	*dup;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	index = 0;
	while (index < len)
	{
		dup[index] = s[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	index;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	index = 0;
	while (index < len)
	{
		sub[index] = s[start + index];
		index++;
	}
	sub[index] = '\0';
	return (sub);
}
