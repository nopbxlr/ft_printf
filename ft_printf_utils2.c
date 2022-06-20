/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctherin <ctherin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:03:00 by ctherin           #+#    #+#             */
/*   Updated: 2022/06/20 18:57:25 by ctherin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int n)
{
	char	*str;
	size_t	len;

	str = ft_unsigned_itoa_base(n, "0123456789");
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	ft_print_lowercase_hex(unsigned int n)
{
	char	*str;
	size_t	len;

	str = ft_itoa_base(n, "0123456789abcdef");
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	ft_print_uppercase_hex(unsigned int n)
{
	char	*str;
	size_t	len;

	str = ft_itoa_base(n, "0123456789ABCDEF");
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
