/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:33:53 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/16 12:53:40 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define A 97
#define D 100
#define Q 113
#define E 101

void	julia_change_c(t_data *data, int key)
{
	if (data->type != JULIA)
		return ;
	if (key == A)
		data->c[X] -= ADJUST_RAT;
	if (key == D)
		data->c[X] += ADJUST_RAT;
	if (key == Q)
		data->c[Y] -= ADJUST_RAT;
	if (key == E)
		data->c[Y] += ADJUST_RAT;
	draw_fractol(data);
}

static int	calculate_point_julia(double x, double y,
	double c[2], int max_iterations)
{
	int		count;
	double	temp;

	count = 0;
	while (count < max_iterations)
	{
		temp = x * x - y * y + c[X];
		y = 2 * x * y + c[Y];
		x = temp;
		if (x * x + y * y >= 4)
			return (count);
		count++;
	}
	return (count);
}

void	draw_julia(t_data *data)
{
	double	step[2];
	int		pix_color;
	int		coordinates[2];
	double	x;
	double	y;

	step[X] = (data->range_max[X] - data->range_min[X]) / WIDTH;
	step[Y] = (data->range_max[Y] - data->range_min[Y]) / HEIGHT;
	coordinates[Y] = 0;
	while (coordinates[Y] < HEIGHT)
	{
		coordinates[X] = 0;
		while (coordinates[X] < WIDTH)
		{
			x = data->range_min[X] + (coordinates[X] * step[X]);
			y = data->range_min[Y] + (coordinates[Y] * step[Y]);
			pix_color = find_colors
				(calculate_point_julia(x, y,
						data->c, data->max_iterations), data);
			put_image_pixel(data, coordinates[X], coordinates[Y], pix_color);
			coordinates[X]++;
		}
		coordinates[Y]++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

t_data	*init_julia(char *c_real, char *c_imag)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->type = JULIA;
	data->color_set = 1;
	if (c_real == NULL || c_imag == NULL)
	{
		data->c[X] = -0.7;
		data->c[Y] = 0.27015;
	}
	else
	{
		data->c[X] = atod(c_real);
		data->c[Y] = atod(c_imag);
	}
	adjust_fractal_bounds(data);
	data->max_iterations = ITERATIONS;
	return (data);
}
