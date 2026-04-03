/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:28:02 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/14 18:36:00 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_minilibx(t_data *data)
{
	t_img_info	*img_info;

	data->mlx = (void *)mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!data->win)
		return (0);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (0);
	data->img_info = (t_img_info *)malloc(sizeof (t_img_info));
	if (!data->img_info)
		return (0);
	img_info = data->img_info;
	img_info->addr = mlx_get_data_addr(data->img,
			&img_info->bpp, &img_info->line_length, &img_info->endian);
	if (!img_info->addr || !img_info->bpp || !img_info->line_length)
		return (0);
	return (1);
}

bool	is_num(char c)
{
	if (c < '0')
		return (false);
	if (c > '9')
		return (false);
	return (true);
}

bool	is_valid_input(char *str)
{
	int	i;

	if (*str == '-')
		str++;
	if (*str == '0' || *str == '1')
	{
		str++;
		if (*str == '.')
		{
			str++;
			i = 0;
			while (str[i] && is_num(str[i]) && i < 16)
				i++;
			if (!str[i])
				return (true);
		}
	}
	else if (*str == '2')
	{
		str++;
		if (*str == '\0'
			|| (*str == '.' && *(str + 1) == '0' && !(*(str + 2))))
			return (true);
	}
	return (false);
}

t_data	*init_data(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "julia", 6))
			return (init_julia(NULL, NULL));
		if (!ft_strncmp(argv[1], "mandelbrot", 12))
			return (init_mandelbrot());
		if (!ft_strncmp(argv[1], "bship", 5))
			return (init_ship());
	}
	if (argc == 4 && is_valid_input(argv[2]) && is_valid_input(argv[3]))
	{
		if (ft_strncmp(argv[1], "julia", 6) == 0)
			return (init_julia(argv[2], argv[3]));
	}
	return (explanational_message());
}
