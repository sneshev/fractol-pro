/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:13:50 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/16 13:30:17 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MIN 0
#define MAX 1

void	scroll(t_data *data, double zoom, double mouse_x, double mouse_y)
{
	double	mouse_pos[2];
	double	new_range[2];

	mouse_pos[X] = data->range_min[X] + (mouse_x / (double)WIDTH)
		* (data->range_max[X] - data->range_min[X]);
	mouse_pos[Y] = data->range_min[Y] + (mouse_y / (double)HEIGHT)
		* (data->range_max[Y] - data->range_min[Y]);
	new_range[X] = (data->range_max[X] - data->range_min[X]) * zoom;
	new_range[Y] = (data->range_max[Y] - data->range_min[Y]) * zoom;
	data->range_min[X] = mouse_pos[X]
		- (mouse_pos[X] - data->range_min[X]) * zoom;
	data->range_max[X] = data->range_min[X] + new_range[X];
	data->range_min[Y] = mouse_pos[Y]
		- (mouse_pos[Y] - data->range_min[Y]) * zoom;
	data->range_max[Y] = data->range_min[Y] + new_range[Y];
	draw_fractol(data);
}

int	set_mouse_events(int button, int mouse_x, int mouse_y, void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	if (button == 1)
		move_center(data, mouse_x, mouse_y);
	if (button == 4)
		scroll(data, ZOOM, mouse_x, mouse_y);
	if (button == 5)
		scroll(data, 1 / ZOOM, mouse_x, mouse_y);
	return (0);
}

void	move_center(t_data *data, double raw_mouse_x, double raw_mouse_y)
{
	double	mouse_pos[2];
	double	range[2][2];

	mouse_pos[X] = data->range_min[X] + (raw_mouse_x / (double)WIDTH)
		* (data->range_max[X] - data->range_min[X]);
	mouse_pos[Y] = data->range_min[Y] + (raw_mouse_y / (double)HEIGHT)
		* (data->range_max[Y] - data->range_min[Y]);
	range[MIN][X] = data->range_min[X];
	range[MAX][X] = data->range_max[X];
	range[MIN][Y] = data->range_min[Y];
	range[MAX][Y] = data->range_max[Y];
	data->range_min[X] = mouse_pos[X] - (range[MAX][X] - range[MIN][X]) / 2.0;
	data->range_max[X] = mouse_pos[X] + (range[MAX][X] - range[MIN][X]) / 2.0;
	data->range_min[Y] = mouse_pos[Y] - (range[MAX][Y] - range[MIN][Y]) / 2.0;
	data->range_max[Y] = mouse_pos[Y] + (range[MAX][Y] - range[MIN][Y]) / 2.0;
	draw_fractol(data);
}

int	close_window(t_data *data)
{
	free_data_exit(data);
	return (1);
}

void	mlx_event_handle(t_data *data)
{
	mlx_hook(data->win, 4, 4, set_mouse_events, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_key_hook(data->win, set_keyhooks, data);
}
