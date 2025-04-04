/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:36:14 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/04 15:43:05 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(int x, int y, t_data *img, int color)
{
	char	*pixel_addr;

	if (x < 0 || y < 0 || x > WIN_SIZE || y > WIN_SIZE)
		return ;
	pixel_addr = img->addr + (y * img->line_length + x * \
		(img->bits_per_pixel / 8));
	*(unsigned int *)pixel_addr = color;
}

void	draw_fractal(t_data *img, t_properties *props, \
						int (*fractal)(t_complex_numbers, int))
{
	int					x;
	int					y;
	int					iter;
	int					color;
	t_complex_numbers	c_nums;

	y = 0;
	while (y < WIN_SIZE - 1)
	{
		x = 0;
		while (x < WIN_SIZE - 1)
		{
			c_nums = get_complex_nums(x, y, props);
			iter = fractal(c_nums, MAX_ITER);
			if (iter < 100)
			{
				color = ((props->color + iter * 300) & 0xFF0000) | \
					((props->color + iter * 500) & 0x00FF00) | \
					((props->color + iter * 700) & 0x0000FF);
				draw_pixel(x, y, img, color);
			}
			++x;
		}
		++y;
	}
}
