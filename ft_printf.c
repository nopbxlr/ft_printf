/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctherin <ctherin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:31:56 by ctherin           #+#    #+#             */
/*   Updated: 2022/06/20 16:55:39 by ctherin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_conversion(va_list ap, char f)
{
	if (f == '%')
		printf("percent\n");
	if (f == 'd' || f == 'i')
		printf("num\n");
	if (f == 's')
		printf("string\n");
	if (f == 'p')
		printf("pointer\n");
	if (f == 'u')
		printf("unsigned\n");
	if (f == 'c')
		printf("char\n");
	if (f == 'x')
		printf("hex (lower)\n");
	if (f == 'X')
		printf("hex (upper)\n");
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
		++i;
	}
	va_end(ap);
	return (0);
}

#include<stdio.h>
int	main(int ac, char **av)
{
	ft_printf(av[1]);
	return (0);
}