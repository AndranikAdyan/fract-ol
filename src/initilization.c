/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:16:45 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/29 16:43:25 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*init_mlx()
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->img_data = (t_data *)malloc(sizeof(t_data));
	mlx->props = (t_properties *)malloc(sizeof(t_properties));
	if (!mlx || !mlx->img_data || !mlx->props)
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_SIZE, WIN_SIZE, "Fract-ol");
	mlx->img_data->img = mlx_new_image(mlx->mlx, WIN_SIZE, WIN_SIZE);
	mlx->img_data->addr = mlx_get_data_addr(mlx->img_data->img, &mlx->img_data->bits_per_pixel, \
		&mlx->img_data->line_length, &mlx->img_data->endian);
	mlx->props->zoom = 4.0;
	mlx->props->shift_x = mlx->props->shift_x / 40;
	mlx->props->shift_y = mlx->props->shift_y / 40;
	mlx->props->color = 0xFF0000;
	mlx->props->color_queue = 0;
	return (mlx);
}

void	free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_image(mlx->mlx, mlx->img_data->img);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx->img_data);
	free(mlx->props);
	exit(0);
}

void	fill_img(t_mlx *mlx)
{
	// int	x;
	// int	y;

	// y = 0;
	// while (y < WIN_SIZE)
	// {
	// 	x = 0;
	// 	while (x < WIN_SIZE)
	// 	{
	// 		draw_pixel(x, y, mlx->img_data, 0x000000);
	// 		++x;
	// 	}
	// 	++y;
	// }
	if (mlx->img_data->img)
	{
		mlx_destroy_image(mlx->mlx, mlx->img_data->img);
		mlx->img_data->img = mlx_new_image(mlx->mlx, WIN_SIZE, WIN_SIZE);
		mlx->img_data->addr = mlx_get_data_addr(mlx->img_data->img, &mlx->img_data->bits_per_pixel, \
			&mlx->img_data->line_length, &mlx->img_data->endian);
	}
	draw_mandelbrot(mlx->img_data, mlx->props);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img_data->img, 0, 0);
}