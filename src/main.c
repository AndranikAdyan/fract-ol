/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:22:53 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/04 20:36:45 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_mlx	*mlx;

	mlx = init_mlx();
	if (!mlx)
		exit (12);
	fill_img(mlx);
	mlx_hook(mlx->window, 2, 1L << 0, keys_handle, mlx);
	mlx_hook(mlx->window, 17, 0, free_mlx, mlx);
	mlx_mouse_hook(mlx->window, mouse_hook, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
