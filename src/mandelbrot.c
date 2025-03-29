/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:21:05 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/29 15:41:28 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex_numbers	*get_complex_nums(int x, int y, t_properties *props)
{
	t_complex_numbers	*c_nums;

	c_nums = (t_complex_numbers *)malloc(sizeof(t_complex_numbers));
	if (!c_nums)
		return (NULL);
	c_nums->cx = ((x - WIN_SIZE / 2) / (WIN_SIZE / props->zoom)) + props->shift_x;
	c_nums->cy = ((y - WIN_SIZE / 2) / (WIN_SIZE / props->zoom)) + props->shift_y;

	return (c_nums);
}

static int	mandelbrot(t_complex_numbers *c_nums, int max_iter)
{
	double	z_x;
	double	z_y;
	double	tmp;
	int		iter;

	z_x = 0;
	z_y = 0;
	iter = 0;
	while (z_x * z_x + z_y * z_y < 4 && iter < max_iter)
	{
		tmp = z_x * z_x - z_y * z_y + c_nums->cx;
		z_y = 2 * z_x * z_y + c_nums->cy;
		z_x = tmp;
		iter++;
	}
	return (iter);
}

void	draw_mandelbrot(t_data *img, t_properties *props)
{
	int					x;
	int					y;
	int					iter;
	int					iter_next;
	t_complex_numbers	*c_nums;

	y = 0;
	while (y < WIN_SIZE - 1)
	{
		x = 0;
		while (x < WIN_SIZE - 1)
		{
			c_nums = get_complex_nums(x, y, props);
			iter = mandelbrot(c_nums, MAX_ITER);
			free(c_nums);
			c_nums = get_complex_nums(x + 1, y, props);
			iter_next = mandelbrot(c_nums, MAX_ITER);
			free(c_nums);
			if (abs(iter - iter_next) > 1)
				draw_pixel(x, y, img, props->color);
			++x;
		}
		++y;
	}
}
