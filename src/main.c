/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:22:53 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/05 23:45:31 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

	mlx = init_mlx();
	if (!mlx)
		exit (12);
	if (!validation(argc, argv, mlx))
		free_mlx(mlx);
	hooks(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
