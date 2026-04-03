/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:54:28 by sneshev           #+#    #+#             */
/*   Updated: 2024/12/02 11:24:44 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

void	det_type(const char spess, va_list *lst_ptr, int *count);
int		ft_printf(const char *format, ...);
void	low_hexa(unsigned long number, int *count);
void	print_addie(void *lst, int *count);
void	print_char(char c, int *count);
void	print_nbr(int n, int *count);
void	print_str(char *str, int *count);
void	putu(unsigned int n, int *count);
void	upp_hexa(unsigned long number, int *count);

#endif
