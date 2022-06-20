/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctherin <ctherin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:31:56 by ctherin           #+#    #+#             */
/*   Updated: 2022/06/20 18:14:06 by ctherin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_conversion(va_list ap, char f)
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

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		total;
	int		i;

	va_start(ap, s);
	total = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			total += ft_handle_conversion(ap, s[++i]);
		else
		{
			write(1, &s[i], 1);
			++total;
		}
		++i;
	}
	va_end(ap);
	return (total);
}

/*#include<stdio.h>
int	main(int ac, char **av)
{
	int a = ft_printf("%x\n", -255);
	int b = printf("%x", -255);
	printf("\n\n%d, %d", a, b);
	return (0);
}*/