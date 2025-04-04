/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:06:27 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/04 23:49:20 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_color(t_mlx *mlx)
{
	mlx->props->color_queue++;
	if (mlx->props->color_queue > 3)
		mlx->props->color_queue = 0;
	if (mlx->props->color_queue == 0)
		mlx->props->color = 0x0000FF;
	else if (mlx->props->color_queue == 1)
		mlx->props->color = 0x3CB371;
	else if (mlx->props->color_queue == 2)
		mlx->props->color = 0xF0FFF0;
}

static void	move_fractal(t_mlx *mlx, int key)
{
	if (key == UP)
		mlx->props->shift_y += mlx->props->zoom / 40;
	else if (key == DOWN)
		mlx->props->shift_y -= mlx->props->zoom / 40;
	else if (key == RIGHT)
		mlx->props->shift_x -= mlx->props->zoom / 40;
	else if (key == LEFT)
		mlx->props->shift_x += mlx->props->zoom / 40;
}

static void	zoom_fractal(t_mlx *mlx, int key)
{
	if (key == ZOOM_IN1 || key == ZOOM_IN2)
		mlx->props->zoom /= 1.1;
	else if (key == ZOOM_OUT1 || key == ZOOM_OUT2)
		mlx->props->zoom *= 1.1;
}

static void	reset_fractol(t_mlx *mlx)
{
	mlx->props->zoom = 4.0;
	mlx->props->shift_x = 0.0;
	mlx->props->shift_y = 0.0;
}

int	keys_handle(int keycode, t_mlx *mlx)
{
	if (keycode == ESC || keycode == KEY_Q)
		free_mlx(mlx);
	else if (keycode == SPACE)
		change_color(mlx);
	else if (keycode == UP || keycode == DOWN || \
			keycode == RIGHT || keycode == LEFT)
		move_fractal(mlx, keycode);
	else if (keycode == ZOOM_IN1 || keycode == ZOOM_IN2 || \
			keycode == ZOOM_OUT1 || keycode == ZOOM_OUT2)
		zoom_fractal(mlx, keycode);
	else if (keycode == KEY_R)
		reset_fractol(mlx);
	fill_img(mlx);
	return (0);
}
