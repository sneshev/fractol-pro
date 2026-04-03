/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:56:12 by sneshev           #+#    #+#             */
/*   Updated: 2024/12/02 11:25:36 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	det_type(const char spess, va_list *lst_ptr, int *count)
{
	if (spess == 'c')
		print_char((char)va_arg(*lst_ptr, int), count);
	else if (spess == 's')
		print_str(va_arg(*lst_ptr, char *), count);
	else if (spess == 'p')
		print_addie(va_arg(*lst_ptr, void *), count);
	else if (spess == 'd' || spess == 'i')
		print_nbr(va_arg(*lst_ptr, int), count);
	else if (spess == 'u')
		putu(va_arg(*lst_ptr, unsigned int), count);
	else if (spess == 'x')
		low_hexa(va_arg(*lst_ptr, unsigned int), count);
	else if (spess == 'X')
		upp_hexa(va_arg(*lst_ptr, unsigned int), count);
	else if (spess == '%')
	{
		write(1, "%%", 1);
		*count += 1;
	}
}
