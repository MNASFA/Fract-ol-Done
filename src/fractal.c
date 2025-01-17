/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:58:15 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/16 13:30:04 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(double c_re, double c_im, int max_iter)
{
	double	z_re;
	double	z_im;
	double	temp;
	int		iter;

	z_re = 0;
	z_im = 0;
	iter = 0;
	while ((z_re * z_re + z_im * z_im <= 4) && (iter < max_iter))
	{
		temp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = temp;
		iter++;
	}
	return (iter);
}

int	julia(t_complex c, t_complex z, int max_iter)
{
	double	temp;
	int		iter;

	iter = 0;
	while (((z.re * z.re + z.im * z.im) <= 4) && (iter < max_iter))
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		iter++;
	}
	return (iter);
}

int	burning_ship(double c_re, double c_im, int max_iter)
{
	double	z_re;
	double	z_im;
	double	temp;
	int		iter;

	z_re = 0.0;
	z_im = 0.0;
	iter = 0;
	while ((z_re * z_re + z_im * z_im <= 4) && (iter < max_iter))
	{
		temp = fabs(z_re * z_re) - fabs(z_im * z_im) + c_re;
		z_im = 2 * fabs(z_re * z_im) + c_im;
		z_re = temp;
		iter++;
	}
	return (iter);
}
