/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:49:56 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/16 11:45:34 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "stdlib.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 65364)
		data->y_offset -= 0.1 / data->zoom;
	else if (keycode == 65362)
		data->y_offset += 0.1 / data->zoom;
	else if (keycode == 65363)
		data->x_offset += 0.1 / data->zoom;
	else if (keycode == 65361)
		data->x_offset -= 0.1 / data->zoom;
	else if (keycode == 99)
		data->color_shift += 10;
	return (0);
}

static double	ft_mouse_im(t_data *data, int y)
{
	double	mouse_im;

	mouse_im = data->min_im + (y / (double)HEIGHT)
		* (data->max_im - data->min_im);
	return (mouse_im);
}

static double	ft_mouse_re(t_data *data, int x)
{
	double	mouse_re;

	mouse_re = data->min_real + (x / (double)WIDTH)
		* (data->max_real - data->min_real);
	return (mouse_re);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = ft_mouse_re(data, x);
	mouse_im = ft_mouse_im(data, y);
	if (button == 4)
	{
		data->zoom *= 1.1;
		data->min_real = mouse_re - (mouse_re - data->min_real) / 1.1;
		data->max_real = mouse_re + (data->max_real - mouse_re) / 1.1;
		data->min_im = mouse_im - (mouse_im - data->min_im) / 1.1;
		data->max_im = mouse_im + (data->max_im - mouse_im) / 1.1;
	}
	else if (button == 5)
	{
		data->zoom /= 1.1;
		data->min_real = mouse_re - (mouse_re - data->min_real) * 1.1;
		data->max_real = mouse_re + (data->max_real - mouse_re) * 1.1;
		data->min_im = mouse_im - (mouse_im - data->min_im) * 1.1;
		data->max_im = mouse_im + (data->max_im - mouse_im) * 1.1;
	}
	return (0);
}
