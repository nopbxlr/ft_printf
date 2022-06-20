/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctherin <ctherin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:23:57 by ctherin           #+#    #+#             */
/*   Updated: 2022/06/20 18:46:29 by ctherin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (nmemb > LONG_MAX || size > LONG_MAX)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t		sz;
	size_t		i;
	char		*dest;

	sz = 0;
	i = 0;
	while (s[sz])
		sz++;
	dest = ft_calloc(sz + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (i < sz)
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}
