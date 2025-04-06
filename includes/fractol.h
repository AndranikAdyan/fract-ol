/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:18:52 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/06 10:55:29 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "structs.h"
# include "keys.h"
# include <math.h>
# include <stdio.h>

# define WIN_SIZE 500
# define MAX_ITER 300

t_mlx				*init_mlx(void);
void				fill_img(t_mlx *mlx);
int					free_mlx(t_mlx *mlx);

int					keys_handle(int keycode, t_mlx *mlx);
int					mouse_hook(int keycode, int x, int y, t_mlx *mlx);

void				draw_pixel(int x, int y, t_data *img, int color);
void				draw_fractal(t_mlx *mlx);
int					animated_color(t_mlx *mlx);
void				something_interesting(t_mlx *mlx, int keycode);
void				julia_control(t_mlx *mlx, int keycode);

t_complex_numbers	get_complex_nums(int x, int y, t_properties *props);

int					mandelbrot(t_properties props);
int					julia(t_properties props);
int					burning_ship(t_properties props);
int					tricorn(t_properties props);
int					celtic_mandelbar(t_properties props);
int					newton(t_properties props);

void				hooks(t_mlx *mlx);

int					validation(int ac, char *av[], t_mlx *mlx);

#endif
