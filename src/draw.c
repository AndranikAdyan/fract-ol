/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:36:14 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/05 20:08:24 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(int x, int y, t_data *img, int color)
{
	char	*pixel_addr;

	if (x < 0 || y < 0 || x >= WIN_SIZE || y >= WIN_SIZE)
		return ;
	pixel_addr = img->addr + (y * img->line_length + x * \
		(img->bits_per_pixel / 8));
	*(unsigned int *)pixel_addr = color;
}

void	draw_fractal(t_mlx *mlx)
{
	int					x;
	int					y;
	int					iter;
	int					color;

	y = 0;
	while (y < WIN_SIZE - 1)
	{
		x = 0;
		while (x < WIN_SIZE - 1)
		{
			mlx->props->c_nums = get_complex_nums(x, y, mlx->props);
			iter = mlx->fractal(*mlx->props);
			if (iter < 100)
			{
				color = ((mlx->props->color + iter * 100) & 0xFF0000) | \
					((mlx->props->color + iter * 300) & 0x00FF00) | \
					((mlx->props->color + iter * 10) & 0x0000FF);
				draw_pixel(x, y, mlx->img_data, color);
			}
			++x;
		}
		++y;
	}
}
