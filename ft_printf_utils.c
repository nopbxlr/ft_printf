/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctherin <ctherin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:17:42 by ctherin           #+#    #+#             */
/*   Updated: 2022/06/20 19:03:13 by ctherin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_print_d_i(int n)
{
	char	*str;
	size_t	len;

	str = ft_itoa_base(n, "0123456789");
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	ft_print_str(char *s)
{
	size_t	len;

	if (!s)
		return (ft_print_str("(null)"));
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_ptr(void *p)
{
	char	*str;
	size_t	len;

	if (!p)
		return (ft_print_str("(nil)"));
	str = ft_unsigned_itoa_base((unsigned long long int)p, "0123456789abcdef");
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, "0x", 2);
	write(1, str, len);
	free(str);
	return (len + 2);
}
