/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:34:57 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/16 13:20:49 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	atod_fractional(char *str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 10.0;
	if (*str == '.')
	{
		str++;
		while (*str && *str >= '0' && *str <= '9')
		{
			fraction += (*str - '0') / divisor;
			divisor *= 10.0;
			str++;
		}
	}
	return (fraction);
}

double	atod(char *str)
{
	double	nb;
	int		sign;

	nb = 0.0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != '.')
	{
		if (*str >= '0' && *str <= '9')
		{
			nb = nb * 10 + (*str - '0');
		}
		else
		{
			return (0.0);
		}
		str++;
	}
	return (sign * (nb + atod_fractional(str)));
}

t_data	*explanational_message(void)
{
	ft_printf("to run: ./fractol *set*\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("⬇️	EXAMPLES	⬇️ \n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("./fractol julia\n");
	ft_printf("./fractol julia c_real c_imag ");
	ft_printf("(./fractol julia 0.12 -1.23451)\n");
	ft_printf("./fractol bship (burning ship fractal)\n");
	return (NULL);
}

void	print_info_julia(void)
{
	ft_printf("\n\n");
	ft_printf("C COORDINATES ADJUSTMENT:\n");
	ft_printf("Q  -> decrease c_imag\n");
	ft_printf("E  -> increase c_imag\n");
	ft_printf("A  -> decrease c_real\n");
	ft_printf("D  -> increase c_real\n");
}

void	print_info(t_data *data)
{
	ft_printf("\033[2J\033[H");
	ft_printf("MOVEMENT:\n");
	ft_printf("Mouse click     -> change centre\n");
	ft_printf("Arrow Up   ⬆️    -> move up\n");
	ft_printf("Arrow Down ⬇️    -> move down\n");
	ft_printf("Arrow Left ⬅️    -> move left\n");
	ft_printf("Arrow Right➡️    -> move right\n");
	ft_printf("\n\n");
	ft_printf("\n");
	ft_printf("ZOOMING:\n");
	ft_printf("W   -> Zoom in\n");
	ft_printf("S   -> Zoom out\n");
	ft_printf("\n\n");
	ft_printf("CHANGE COLORS:\n");
	ft_printf("0   -> base\n");
	ft_printf("1   -> tropical\n");
	ft_printf("2   -> cool blue\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("CHANGE ITERATIONS:\n");
	ft_printf("<   -> decrease iterations\n");
	ft_printf(">   -> increase iterations\n");
	if (data->type == JULIA)
		print_info_julia();
	ft_printf("\n\niterations: %d", data->max_iterations);
}
