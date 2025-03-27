/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:18:52 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/28 00:32:10 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARCTOL_H
# define FARCTOL_H

# include "mlx.h"
# include "libft.h"
# include "structs.h"

# define WIDTH 720
# define HEIGHT 720

void	draw_pixel(int x, int y, t_data *img, int color);
void	draw_mandelbrot(t_data *img);

#endif