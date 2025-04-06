/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:22:53 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/06 14:55:17 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

	if (!validation(argc, argv))
		return (1);
	mlx = init_mlx();
	if (!mlx)
		exit (12);
	set_fractal(mlx, argv[1]);
	hooks(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
