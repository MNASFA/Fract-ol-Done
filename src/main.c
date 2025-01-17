/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:19:02 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/16 14:36:13 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	check_valid_argument(const char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (str[i] == '.')
		return (0);
	else if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			i++;
		else if (str[i] == '.' && flag == 0)
		{
			i++;
			flag = 1;
		}
		else
			return (0);
	}
	if (str[i - 1] == '.')
		return (0);
	return (1);
}

static int	helper_function(int argc, char **argv)
{
	if (argc != 4)
	{
		perror ("Usage : ./fract-ol julia <julia_re> <julia_im>\n");
		return (1);
	}
	if (!check_valid_argument(argv[2]) || !check_valid_argument(argv[3]))
	{
		perror("julia set parameters must be valid float numbers !");
		return (1);
	}
	return (0);
}

static int	parse_argument(int argc, char **argv, t_data *data)
{
	if (argc < 2)
	{
		perror ("Usage: ./fract-ol <mandelbrot|julia> [julia_re julia_im]\n");
		return (1);
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		data->is_mandelbrot = 1;
	else if (ft_strcmp(argv[1], "burning_ship") == 0)
		data->is_burning_ship = 1;
	else if (ft_strcmp (argv[1], "julia") == 0)
	{
		if (helper_function(argc, argv))
			return (1);
		data->is_julia = 1;
		data->julia_c_re = ft_atof(argv[2]);
		data->julia_c_im = ft_atof(argv[3]);
	}
	else
	{
		perror("Invalid Argument !!");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.min_real = -2;
	data.max_real = 2;
	data.min_im = 2;
	data.max_im = -2;
	data.max_iter = 100;
	data.color_shift = 0;
	data.is_burning_ship = 0;
	data.is_julia = 0;
	data.is_mandelbrot = 0;
	if (parse_argument(argc, argv, &data) != 0)
		return (1);
	if (init_window(&data) != 0)
		return (1);
	mlx_loop_hook(data.mlx, render_fractal, &data);
	mlx_key_hook(data.window, handle_key, &data);
	mlx_mouse_hook(data.window, handle_mouse, &data);
	mlx_hook(data.window, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}
