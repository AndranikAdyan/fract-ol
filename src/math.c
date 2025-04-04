/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:42:42 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/04 15:40:36 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_numbers	get_complex_nums(int x, int y, t_properties *props)
{
	t_complex_numbers	c_nums;

	c_nums.cx = ((x - WIN_SIZE / 2) / (WIN_SIZE / props->zoom)) + \
					props->shift_x;
	c_nums.cy = ((y - WIN_SIZE / 2) / (WIN_SIZE / props->zoom)) + \
					props->shift_y;
	return (c_nums);
}
