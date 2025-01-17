/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:58:05 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/16 15:22:01 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*img_addr;
	int		bits_per_pixels;
	int		line_len;
	int		endian;

	int		fractal_type;
	double	zoom;
	double	x_offset;
	double	y_offset;
	double	min_real;
	double	max_real;
	double	min_im;
	double	max_im;
	int		max_iter;

	double	julia_c_re;
	double	julia_c_im;

	int		is_julia;
	int		is_burning_ship;
	int		is_mandelbrot;

	double	c_real;
	double	c_im;
	int		iter ;
	int		color;
	double	z_re;
	double	z_im;
	int		x;
	int		y;

	int		color_shift;
}	t_data;

typedef struct s_atof_data
{
	int		i;
	int		sign;
	double	res;
	double	fraction;
	double	divisor;
}	t_adata;

int		init_window(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
int		render_fractal(t_data *data);
int		mandelbrot(double c_re, double c_im, int max_iter);
int		julia(t_complex c, t_complex z, int max_iter);
double	ft_atof(const char *str);
int		handle_mouse(int button, int x, int y, t_data *data);
int		handle_key(int keycode, t_data *data);
int		close_window(t_data *data);
int		burning_ship(double c_re, double c_im, int max_iter);
int		ft_strcmp(char *s1, char *s2);

#endif