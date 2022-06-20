/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctherin <ctherin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:31:20 by ctherin           #+#    #+#             */
/*   Updated: 2022/06/20 18:13:56 by ctherin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

/*
	ft_printf.c
*/
int		ft_handle_conversion(va_list ap, char f);
int		ft_printf(const char *s, ...);

/*
	ft_printf_utils.c
*/
int		ft_print_percent(void);
int		ft_print_d_i(int n);
int		ft_print_str(char *s);
int		ft_print_char(char c);
int		ft_print_ptr(void *ptr);

/*
	ft_printf_utils2.c
*/
int		ft_print_u(unsigned int n);
int		ft_print_lowercase_hex(unsigned int n);
int		ft_print_uppercase_hex(unsigned int n);

/*
	ft_itoa_base.c
*/
char	*ft_itoa_base(long long int n, char *base);

/*
	ft_mem_utils.c
*/
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);

#endif