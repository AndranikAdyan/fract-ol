/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic_mandelbar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:47:52 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/06 00:56:59 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	celtic_mandelbar(t_properties props)
{
	double	z_x;
	double	z_y;
	double	tmp;
	int		iter;

	z_x = 0;
	z_y = 0;
	iter = 0;
	while (z_x * z_x + z_y * z_y < 4 && iter < MAX_ITER)
	{
		tmp = z_x * z_x - z_y * z_y;
		z_y = -2 * z_x * z_y + props.c_nums.cy;
		if (tmp < 0)
			tmp *= -1;
		z_x = tmp + props.c_nums.cx;
		iter++;
	}
	return (iter);
}
