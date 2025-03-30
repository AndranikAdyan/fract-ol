/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:21:05 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/30 10:47:00 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex_numbers *c_nums, int max_iter)
{
	double	z_x;
	double	z_y;
	double	tmp;
	int		iter;

	z_x = 0;
	z_y = 0;
	iter = 0;
	while (z_x * z_x + z_y * z_y < 4 && iter < max_iter)
	{
		tmp = z_x * z_x - z_y * z_y + c_nums->cx;
		z_y = 2 * z_x * z_y + c_nums->cy;
		z_x = tmp;
		iter++;
	}
	return (iter);
}
