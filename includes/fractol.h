/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:18:52 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/28 13:57:39 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARCTOL_H
# define FARCTOL_H

# include "mlx.h"
# include "libft.h"
# include "structs.h"

# define WIN_SIZE 720
# define MAX_ITER 100

# define ESC 65307
# define Q 113

t_mlx	*init_mlx();

int	close_win(int keycode, t_mlx *mlx);

void	draw_pixel(int x, int y, t_data *img, int color);
void	draw_mandelbrot(t_data *img, t_properties props);

#endif