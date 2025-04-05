/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 10:43:41 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/05 20:13:17 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_properties props)
{
	double	z_x;
	double	z_y;
	double	tmp;
	int		iter;

	z_x = props.c_nums.cx;
	z_y = props.c_nums.cy;
	iter = 0;
	while (z_x * z_x + z_y * z_y < 4 && iter < MAX_ITER)
	{
		tmp = z_x * z_x - z_y * z_y + props.coords.x;
		z_y = 2 * z_x * z_y + props.coords.y;
		z_x = tmp;
		iter++;
	}
	return (iter);
}
