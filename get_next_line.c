/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebin-ahm <ebin-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:48:43 by ebin-ahm          #+#    #+#             */
/*   Updated: 2026/01/22 17:48:46 by ebin-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(const char *stash)
{
	size_t	index;

	if (!stash || stash[0] == '\0')
		return (NULL);
	index = 0;
	while (stash[index] && stash[index] != '\n')
		index++;
	if (stash[index] == '\n')
		return (ft_substr(stash, 0, index + 1));
	return (ft_strdup(stash));
}

char	*update_stash(char *stash)
{
	size_t	index;
	char	*new_stash;

	if (!stash)
		return (NULL);
	index = 0;
	while (stash[index] && stash[index] != '\n')
		index++;
	if (stash[index] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_substr(stash, index + 1, ft_strlen(stash) - (index + 1));
	free(stash);

	if (!new_stash || new_stash[0] == '\0')
	{
		free(new_stash);
		return ((NULL));
	}
	return (new_stash);
}

char	*get_next_line(int fd)
{

}
