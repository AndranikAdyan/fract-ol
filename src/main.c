/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:22:53 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/28 00:16:56 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_mlx	*mlx;
	t_data	*img;

	mlx = malloc(sizeof(t_mlx));
	img = malloc(sizeof(t_data));
	if (!mlx || !img)
		return (1);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Fract-ol");
	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	draw_mandelbrot(img);
	mlx_put_image_to_window(mlx->mlx, mlx->window, img->img, 0, 0);
	mlx_loop(mlx->mlx);
	free(img);
	free(mlx);
	return (0);
}
