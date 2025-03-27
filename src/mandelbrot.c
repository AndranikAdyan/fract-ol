/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:21:05 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/28 00:28:10 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_numbers	*get_complex_nums(int x, int y)
{
	t_complex_numbers	*c_nums;
	double	zoom;
	double	shift_x;
	double	shift_y;

	c_nums = (t_complex_numbers *)malloc(sizeof(t_complex_numbers));
	if (!c_nums)
		return (NULL);
	zoom = 4.0;
	shift_x = shift_y = 0.0;
	c_nums->cx = ((double)(x - WIDTH / 2) / (WIDTH / zoom)) + shift_x;
	c_nums->cy = ((double)(y - HEIGHT / 2) / (HEIGHT / zoom)) + shift_y;

	return (c_nums);
}

int	mandelbrot(t_complex_numbers *c_nums, int max_iter)
{
	double	z_x;
	double	z_y;
	double	tmp;
	int		iter;

	z_x = z_y = iter = 0;
	while (z_x * z_x + z_y * z_y < 4 && iter < max_iter)
	{
		tmp = z_x * z_x - z_y * z_y + c_nums->cx;
		z_y = 2 * z_x * z_y + c_nums->cy;
		z_x = tmp;
		iter++;
	}
	return (iter);
}

void	draw_mandelbrot(t_data *img)
{
	int					x;
	int					y;
	int					color;
	int					max_iter;
	t_complex_numbers	*c_nums;

	max_iter = 100;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_nums = get_complex_nums(x, y);
			color = mandelbrot(c_nums, max_iter) / max_iter * 0x00FF0000;
			draw_pixel(x, y, img, color);
			free(c_nums);
			++x;
		}
	++y;
	}
}