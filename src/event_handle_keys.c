/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle_keys.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:41:09 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/16 12:42:06 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define ESC 65307 
#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364
#define W 119
#define S 115
#define A 97
#define D 100
#define Q 113
#define E 101
#define ITERPLUS 46
#define ITERMIN 44

void	zoom_image(t_data *data, double zoom)
{
	double	new_range[2];
	double	center[2];

	center[X] = (data->range_max[X] + data->range_min[X]) / 2.0;
	center[Y] = (data->range_max[Y] + data->range_min[Y]) / 2.0;
	new_range[X] = (data->range_max[X] - data->range_min[X]) * zoom;
	new_range[Y] = (data->range_max[Y] - data->range_min[Y]) * zoom;
	data->range_min[X] = center[X] - new_range[X] / 2.0;
	data->range_max[X] = center[X] + new_range[X] / 2.0;
	data->range_min[Y] = center[Y] - new_range[Y] / 2.0;
	data->range_max[Y] = center[Y] + new_range[Y] / 2.0;
	draw_fractol(data);
}

void	change_iterations(t_data *data, int key)
{
	if (key == ITERPLUS)
		data->max_iterations = (int)(data->max_iterations
				* ITERATION_RAT + 0.5);
	else if (key == ITERMIN)
		data->max_iterations = (int)(data->max_iterations
				/ ITERATION_RAT + 0.5);
	draw_fractol(data);
	ft_printf("\033[2K\r");
	ft_printf("iterations: %d", data->max_iterations);
}

int	set_keyhooks(int key, t_data *data)
{
	if (key == ESC)
		free_data_exit(data);
	if (key == W)
		zoom_image(data, ZOOM);
	if (key == S)
		zoom_image(data, 1 / ZOOM);
	if (key == UP)
		move_center(data, WIDTH / 2, HEIGHT / 2 - HEIGHT * MOVE);
	if (key == DOWN)
		move_center(data, WIDTH / 2, HEIGHT / 2 + HEIGHT * MOVE);
	if (key == LEFT)
		move_center(data, WIDTH / 2 - WIDTH * MOVE, HEIGHT / 2);
	if (key == RIGHT)
		move_center(data, WIDTH / 2 + WIDTH * MOVE, HEIGHT / 2);
	if (key >= 48 && key <= 57)
	{
		data->color_set = key - 48;
		draw_fractol(data);
	}
	if (key == D || key == A || key == Q || key == E)
		julia_change_c(data, key);
	if (key == ITERMIN || key == ITERPLUS)
		change_iterations(data, key);
	return (1);
}
