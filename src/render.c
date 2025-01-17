/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:27:13 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/16 14:24:01 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	get_color(int iter, int max_iter, int color_shift)
{
	if (iter == max_iter)
		return (0x000000);
	if (iter < max_iter / 4)
		return (0xff0000 + color_shift);
	else if (iter < max_iter / 2)
		return (0x00ff00 + color_shift);
	else if (iter < 3 * max_iter / 4)
		return (0x0000ff + color_shift);
	else
		return (0xffff00 + color_shift);
}

static void	init_c(t_data *data)
{
	double	scale_real;
	double	scale_im;

	scale_real = (data->x / (double)WIDTH) * (data->max_real - data->min_real);
	scale_im = (data->y / (double)HEIGHT) * (data->max_im - data->min_im);
	data->c_real = data->min_real + scale_real + data->x_offset;
	data->c_im = data->min_im + scale_im + data->y_offset;
}

static void	helpfunc(t_data *data)
{
	t_complex	z;
	t_complex	c;

	if (data->is_mandelbrot)
		data->iter = mandelbrot(data->c_real, data->c_im, data->max_iter);
	else if (data->is_julia)
	{	
		z.re = data->c_real;
		z.im = data->c_im;
		c.re = data->julia_c_re;
		c.im = data->julia_c_im;
		data->iter = julia(c, z, data->max_iter);
	}
	else
		data->iter = burning_ship(data->c_real, data->c_im, data->max_iter);
}

int	render_fractal(t_data *data)
{
	data->y = 0;
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			init_c(data);
			helpfunc(data);
			data->color = get_color(data->iter, data->max_iter,
					data->color_shift);
			put_pixel(data, data->x, data->y, data->color);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	return (0);
}
