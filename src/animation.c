/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:35:01 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/04 23:52:40 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	animated_color(t_mlx *mlx)
{
	if (mlx->props->color_queue == 3)
	{
		if (mlx->props->color >= 0xFFFFFF)
			mlx->props->color_decreasing = 1;
		else if (mlx->props->color <= 0x000000)
			mlx->props->color_decreasing = 0;
		if (mlx->props->color_decreasing)
			mlx->props->color -= 0x000101;
		else
			mlx->props->color += 0x000101;
		fill_img(mlx);
	}
	return (0);
}
