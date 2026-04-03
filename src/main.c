/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:29:11 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/16 13:22:15 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = init_data(argc, argv);
	if (!data)
		return (1);
	if (!init_minilibx(data))
	{
		free_data_exit(data);
		return (1);
	}
	draw_fractol(data);
	print_info(data);
	mlx_event_handle(data);
	mlx_loop(data->mlx);
}
