/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:26:02 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/16 15:22:10 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		perror("Error : failed to initialize mlx\n");
		return (1);
	}
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!data->window)
	{
		perror("Error : failed to create a window\n");
		return (1);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		perror("Error : failed to create image\n");
		return (1);
	}
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixels,
			&data->line_len, &data->endian);
	data->zoom = 1.0;
	data->x_offset = 0.0;
	data->y_offset = 0.0;
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

static t_adata	init_adata(void)
{
	t_adata	data;

	data.i = 0;
	data.sign = 1;
	data.res = 0.0;
	data.fraction = 0.0;
	data.divisor = 1.0;
	return (data);
}

double	ft_atof(const char *str)
{
	t_adata	adata;

	adata = init_adata();
	if (str[adata.i] == '-' || str[adata.i] == '+')
	{
		if (str[adata.i] == '-')
			adata.sign = -1;
		adata.i++;
	}
	while (str[adata.i] >= 48 && str[adata.i] <= 57)
		adata.res = adata.res * 10 + (str[adata.i++] - 48);
	if (str[adata.i] == '.')
	{
		adata.i++;
		while (str[adata.i] >= 48 && str[adata.i] <= 57)
		{
			adata.fraction = adata.fraction * 10 + (str[adata.i] - 48);
			adata.divisor *= 10;
			adata.i++;
		}
		adata.res += adata.fraction / adata.divisor;
	}
	return (adata.res * adata.sign);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	int		x_offset;
	int		y_offset;
	char	*pixel;

	x_offset = x * (data->bits_per_pixels / 8);
	y_offset = y * data->line_len;
	pixel = data->img_addr + (x_offset + y_offset);
	*(unsigned int *)pixel = color;
}
