/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:56:35 by sneshev           #+#    #+#             */
/*   Updated: 2024/12/02 11:22:56 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	lst;
	int		count;

	count = 0;
	if (format == NULL)
		return (-1);
	va_start(lst, format);
	while (*format)
	{
		if (*format == '%')
		{
			det_type(*(format + 1), &lst, &count);
			format += 2;
		}
		else
		{
			write(1, format, 1);
			format++;
			count++;
		}
	}
	return (count);
}
