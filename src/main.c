/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:22:53 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/28 13:51:04 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_mlx	*mlx;
	t_properties	props = {4.0, 0.0, 0.0};

	mlx = init_mlx();
	if (!mlx)
		exit (12);
	draw_mandelbrot(mlx->img_data, props);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img_data->img, 0, 0);

	mlx_key_hook(mlx->window, close_win, mlx);
	
	mlx_loop(mlx->mlx);
	return (0);
}
