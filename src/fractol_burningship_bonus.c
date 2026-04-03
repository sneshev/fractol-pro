/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_burningship.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:40:44 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/16 12:46:21 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define TEMP 2

// z(n+1) = (|z_x| + i|z_y|)^2 + c;
static int	calculate_point(double *c, int max_iterations)
{
	double	z[3];
	double	abs_z[2];
	int		count;

	count = 0;
	z[X] = 0;
	z[Y] = 0;
	while (count < max_iterations)
	{
		abs_z[X] = fabs(z[X]);
		abs_z[Y] = fabs(z[Y]);
		z[TEMP] = abs_z[X] * abs_z[X] - abs_z[Y] * abs_z[Y] + c[X];
		z[Y] = 2 * abs_z[X] * abs_z[Y] + c[Y];
		z[X] = z[TEMP];
		if (z[X] * z[X] + z[Y] * z[Y] >= 4)
			return (count);
		count++;
	}
	return (count);
}

void	draw_ship(t_data *data)
{
	double	step[2];
	double	c[2];
	int		pix_color;
	int		x;
	int		y;

	step[X] = (data->range_max[X] - data->range_min[X]) / WIDTH;
	step[Y] = (data->range_max[Y] - data->range_min[Y]) / HEIGHT;
	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		c[Y] = data->range_min[Y] + y * step[Y];
		while (x < WIDTH)
		{
			c[X] = data->range_min[X] + x * step[X];
			pix_color = find_colors(calculate_point
					(c, data->max_iterations), data);
			put_image_pixel(data, x, y, pix_color);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

t_data	*init_ship(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof (t_data));
	if (!data)
		return (NULL);
	data->type = BURNING_SHIP;
	data->color_set = 1;
	data->c[X] = 0.0;
	data->c[Y] = 0.0;
	adjust_fractal_bounds(data);
	data->max_iterations = ITERATIONS;
	return (data);
}
