/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:52:09 by sneshev           #+#    #+#             */
/*   Updated: 2024/12/02 11:24:06 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

void	print_addie(void *lst, int *count)
{
	uintptr_t	addie;

	if (!lst)
	{
		write (1, "(nil)", 5);
		*count += 5;
		return ;
	}
	addie = (uintptr_t)lst;
	write(1, "0x", 2);
	*count += 2;
	low_hexa(addie, count);
}
