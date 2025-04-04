/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 10:43:41 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/04 13:51:29 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex_numbers c_nums, int max_iter)
{
	double	z_x;
	double	z_y;
	double	tmp;
	int		iter;

	z_x = c_nums.cx;
	z_y = c_nums.cy;
	iter = 0;
	while (z_x * z_x + z_y * z_y < 4 && iter < max_iter)
	{
		tmp = z_x * z_x - z_y * z_y + (-0.7);
		z_y = 2 * z_x * z_y + 0.27015;
		z_x = tmp;
		iter++;
	}
	return (iter);
}