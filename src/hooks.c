/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:43:21 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/05 22:45:08 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void hooks(t_mlx *mlx)
{
	mlx_hook(mlx->window, 2, 1L << 0, keys_handle, mlx);
	mlx_mouse_hook(mlx->window, mouse_hook, mlx);
	mlx_loop_hook(mlx->mlx, animated_color, mlx);
	mlx_hook(mlx->window, 17, 0, free_mlx, mlx);
}