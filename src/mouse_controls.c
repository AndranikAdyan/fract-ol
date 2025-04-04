/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:46:57 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/04 15:43:45 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mouse_zoom(t_mlx *mlx, int keycode, int x, int y)
{
	double	center_x;
	double	center_y;
	double	zoom_factor;
	double	prev_zoom;

	prev_zoom = mlx->props->zoom;
	center_x = WIN_SIZE / 2.0;
	center_y = WIN_SIZE / 2.0;
	if (keycode == SCROLL_UP)
		zoom_factor = 1.1;
	else
		zoom_factor = 1 / 1.1;
	mlx->props->zoom *= zoom_factor;
	mlx->props->shift_x -= (x - center_x) / WIN_SIZE * 2 * \
							(mlx->props->zoom - prev_zoom);
	mlx->props->shift_y -= (y - center_y) / WIN_SIZE * 2 * \
							(mlx->props->zoom - prev_zoom);
}

int	mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == SCROLL_DOWN || keycode == SCROLL_UP)
		mouse_zoom(mlx, keycode, x, y);
	fill_img(mlx);
	return (0);
}
