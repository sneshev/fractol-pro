/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefuntu <stefuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:09:59 by sneshev           #+#    #+#             */
/*   Updated: 2025/10/29 11:26:34 by stefuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdint.h>
#include <math.h>

#define BASIC 0
#define TROPICAL 1

#define RED 0xFF0000
#define BLACK 0x000000
#define WHITE 0x00FFFFFF
#define GREEN 0x0000FF00

int	colors_tropical(int iterations, int max_iterations)
{
	if (iterations == max_iterations)
		return (0x000000);
	if (iterations < 6)
		return (RED + iterations * 99);
	return (RED + iterations * 50);
}

int	colors_test(int iterations, int max_iterations)
{
	if (iterations < 6)
		return (BLACK);
	if (iterations == max_iterations)
		return (0x000000);
	return (GREEN + iterations * 50);
}

int	colors_basic(int iterations, int max_iterations)
{
	if (iterations == max_iterations)
		return (BLACK);
	return (WHITE);
}

int	find_colors(int iterations, t_data *data)
{
	int	max_iterations;
	int	color_set;

	max_iterations = data->max_iterations;
	color_set = data->color_set;
	if (color_set == BASIC)
		return (colors_basic(iterations, max_iterations));
	if (color_set == TROPICAL)
		return (colors_tropical(iterations, max_iterations));
	return (colors_test(iterations, max_iterations));
}
