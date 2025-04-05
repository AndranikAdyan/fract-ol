/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:41:23 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/06 00:56:33 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_control(t_mlx *mlx, int keycode)
{
	if (keycode == KEY_W)
		mlx->props->coords.x += 0.05;
	else if (keycode == KEY_S)
		mlx->props->coords.x -= 0.05;
	else if (keycode == KEY_A)
		mlx->props->coords.y += 0.05;
	else if (keycode == KEY_D)
		mlx->props->coords.y -= 0.05;
	fill_img(mlx);
}
