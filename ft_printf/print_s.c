/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:48:20 by sneshev           #+#    #+#             */
/*   Updated: 2024/12/02 11:20:29 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(char *str, int *count)
{
	if (str == NULL)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		*count += 1;
	}
}
