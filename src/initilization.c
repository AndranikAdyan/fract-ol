/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:16:45 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/28 13:31:42 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*init_mlx()
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->img_data = malloc(sizeof(t_data));
	if (!mlx || !mlx->img_data)
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_SIZE, WIN_SIZE, "Fract-ol");
	mlx->img_data->img = mlx_new_image(mlx->mlx, WIN_SIZE, WIN_SIZE);
	mlx->img_data->addr = mlx_get_data_addr(mlx->img_data->img, &mlx->img_data->bits_per_pixel, \
		&mlx->img_data->line_length, &mlx->img_data->endian);
	return (mlx);
}