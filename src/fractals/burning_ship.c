/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:25:55 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/06 00:56:54 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(t_properties props)
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
		tmp = z_x * z_x - z_y * z_y + props.c_nums.cx;
		z_y = 2 * fabs(z_x) * fabs(z_y) + props.c_nums.cy;
		z_x = tmp;
		iter++;
	}
	return (iter);
}
