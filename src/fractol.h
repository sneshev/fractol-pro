/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefuntu <stefuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:22:23 by sneshev           #+#    #+#             */
/*   Updated: 2025/10/28 21:37:08 by stefuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdbool.h>
# include <math.h>

# define MANDELBROT 0
# define JULIA 1
# define BURNING_SHIP 2

# define ITERATIONS 50
# define ITERATION_RAT 1.1
# define COLOR_SET 0

# define HEIGHT 1000
# define WIDTH 1300

# define ZOOM 0.7
# define MOVE 0.05
# define ADJUST_RAT 0.01

# define MIN_REAL -2.0
# define MAX_REAL  2.0
# define MIN_IMAG -2.0
# define MAX_IMAG  2.0

# define X 0
# define Y 1

typedef struct s_img_info
{
	int		bpp;
	int		line_length;
	int		endian;
	char	*addr;
}	t_img_info;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	t_img_info	*img_info;
	int			color_set;
	int			type;
	double		c[2];
	double		range_min[2];
	double		range_max[2];
	int			max_iterations;
}	t_data;

// initialize
t_data	*init_data(int argc, char *argv[]);
int		init_minilibx(t_data *data);

//fractols
void	draw_fractol(t_data *data);
int		find_colors(int iterations, t_data *data);
void	put_image_pixel(t_data *data, int x, int y, int color);

// event_handlers
void	mlx_event_handle(t_data *data);
int		set_keyhooks(int key, t_data *data);
void	move_center(t_data *data, double raw_mouse_x, double raw_mouse_y);

// utils
void	adjust_fractal_bounds(t_data *data);
t_data	*explanational_message(void);
void	free_data_exit(t_data *data);
double	atod(char *str);
void	print_info(t_data *data);

//mandelbrot
t_data	*init_mandelbrot(void);
void	draw_mandelbrot(t_data *data);

//julia
t_data	*init_julia(char *c_real, char *c_imag);
void	draw_julia(t_data *data);
void	julia_change_c(t_data *data, int key);

//burning ship
void	draw_ship(t_data *data);
t_data	*init_ship(void);

// helpers
// void	print_coordinates(t_data *data);
// void	print_data(t_data *data);

#endif