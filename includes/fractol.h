/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:18:52 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/29 16:14:41 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARCTOL_H
# define FARCTOL_H

# include "mlx.h"
# include "libft.h"
# include "structs.h"
# include "keys.h"

# define WIN_SIZE 500
# define MAX_ITER 50

t_mlx	*init_mlx();
void	fill_img(t_mlx *mlx);
void	free_mlx(t_mlx *mlx);

void	draw_pixel(int x, int y, t_data *img, int color);
void	draw_mandelbrot(t_data *img, t_properties *props);
int		keys_handle(int keycode, t_mlx *mlx);

#endif