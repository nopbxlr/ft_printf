/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctherin <ctherin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:23:03 by ctherin           #+#    #+#             */
/*   Updated: 2022/06/20 17:54:01 by ctherin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_base_length(char *base)
{
	unsigned int	length;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	length = ft_strlen(base);
	if (length <= 1)
		return (0);
	while (i < length)
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (!(base[i] >= 32 && base[i] <= 126))
			return (0);
		while (j < length)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (length);
}

static int	get_nb_len(long long int n, unsigned int base_length)
{
	int		len;
	int		is_neg;

	len = 0;
	is_neg = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		is_neg = 1;
	}
	while (n > 0)
	{
		len++;
		n /= base_length;
	}
	return (len + is_neg);
}

char	*ft_itoa_base(long long int n, char *base)
{
	char			*ptr;
	int				nb_len;
	unsigned int	base_length;

	base_length = get_base_length(base);
	if (!base_length)
		return (NULL);
	nb_len = get_nb_len(n, base_length);
	ptr = ft_calloc(nb_len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		ptr[0] = '-';
	}
	if (n == 0)
		ptr[0] = '0';
	while (n > 0)
	{
		ptr[nb_len - 1] = base[(n % base_length)];
		n /= base_length;
		nb_len--;
	}
	return (ptr);
}
