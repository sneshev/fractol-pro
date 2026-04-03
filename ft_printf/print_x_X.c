/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:54:03 by sneshev           #+#    #+#             */
/*   Updated: 2024/12/02 11:21:02 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	low_hexa(unsigned long number, int *count)
{
	unsigned int	c;
	const char		str[] = "0123456789abcdef";

	if (number >= 16)
	{
		low_hexa(number / 16, count);
	}
	c = (number % 16);
	write (1, &str[c], 1);
	*count += 1;
}

void	upp_hexa(unsigned long number, int *count)
{
	unsigned int	c;
	const char		str[] = "0123456789ABCDEF";

	if (number >= 16)
	{
		upp_hexa(number / 16, count);
	}
	c = (number % 16);
	write (1, &str[c], 1);
	*count += 1;
}
