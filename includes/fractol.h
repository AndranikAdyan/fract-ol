/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:18:52 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/30 10:47:48 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARCTOL_H
# define FARCTOL_H

# include "mlx.h"
# include "libft.h"
# include "structs.h"
# include "keys.h"

# define WIN_SIZE 500
# define MAX_ITER 300

t_mlx				*init_mlx();
void				fill_img(t_mlx *mlx);
void				free_mlx(t_mlx *mlx);

int					keys_handle(int keycode, t_mlx *mlx);

void				draw_pixel(int x, int y, t_data *img, int color);
void				draw_fractal(t_data *img, t_properties *props, int (*fractal)(t_complex_numbers *, int));

t_complex_numbers	*get_complex_nums(int x, int y, t_properties *props);

int					mandelbrot(t_complex_numbers *c_nums, int max_iter);
int					julia(t_complex_numbers *c_nums, int max_iter);

#endif