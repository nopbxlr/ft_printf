/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctherin <ctherin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:31:56 by ctherin           #+#    #+#             */
/*   Updated: 2022/06/22 18:08:19 by ctherin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_conversion(va_list ap, char f)
{
	if (f == '%')
		return (ft_print_percent());
	if (f == 'd' || f == 'i')
		return (ft_print_d_i(va_arg(ap, int)));
	if (f == 's')
		return (ft_print_str(va_arg(ap, char *)));
	if (f == 'p')
		return (ft_print_ptr(va_arg(ap, void *)));
	if (f == 'u')
		return (ft_print_u(va_arg(ap, unsigned int)));
	if (f == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (f == 'x')
		return (ft_print_lowercase_hex(va_arg(ap, unsigned int)));
	if (f == 'X')
		return (ft_print_uppercase_hex(va_arg(ap, unsigned int)));
	return (0);
}

static int	ft_print_from_to(const char *s, int from, int to)
{
	int	total;

	total = to - from;
	write(1, s + from, total);
	return (total);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		total;
	int		i;
	int		ofs;

	if (!s)
		return (0);
	va_start(ap, s);
	total = 0;
	i = 0;
	ofs = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			total += ft_print_from_to(s, ofs, i);
			total += ft_handle_conversion(ap, s[++i]);
			ofs = i + 1;
		}
		++i;
	}
	total += ft_print_from_to(s, ofs, i);
	va_end(ap);
	return (total);
}
