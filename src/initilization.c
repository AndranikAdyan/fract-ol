/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:16:45 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/06 14:52:48 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_props(t_mlx *mlx)
{
	mlx->props->zoom = 4.0;
	mlx->props->shift_x = 0.0;
	mlx->props->shift_y = 0.0;
	mlx->props->color = 0x0000FF;
	mlx->props->color_queue = 0;
	mlx->props->color_decreasing = 0;
	mlx->props->c_nums = (t_complex_numbers){0, 0};
	mlx->props->coords = (t_coords){-0.7, -0.27015};
	mlx->props->interesting = 10;
	mlx->props->animation = 1;
}

void	set_fractal(t_mlx *mlx, char *fractal)
{
	if (ft_strcmp(fractal, "mandelbrot") == 0)
		mlx->fractal = mandelbrot;
	else if (ft_strcmp(fractal, "julia") == 0)
		mlx->fractal = julia;
	else if (ft_strcmp(fractal, "tricorn") == 0)
		mlx->fractal = tricorn;
	else if (ft_strcmp(fractal, "celtic_mandelbar") == 0)
		mlx->fractal = celtic_mandelbar;
	else if (ft_strcmp(fractal, "burning_ship") == 0)
		mlx->fractal = burning_ship;
	else if (ft_strcmp(fractal, "newton") == 0)
		mlx->fractal = newton;
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->img_data = (t_data *)malloc(sizeof(t_data));
	if (!mlx->img_data)
		return (free(mlx), NULL);
	mlx->props = (t_properties *)malloc(sizeof(t_properties));
	if (!mlx->props)
		return (free(mlx->img_data), free(mlx), NULL);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_SIZE, WIN_SIZE, "Fract-ol");
	mlx->img_data->img = mlx_new_image(mlx->mlx, WIN_SIZE, WIN_SIZE);
	mlx->img_data->addr = mlx_get_data_addr(mlx->img_data->img, \
						&mlx->img_data->bits_per_pixel, \
						&mlx->img_data->line_length, &mlx->img_data->endian);
	init_props(mlx);
	mlx->fractal = celtic_mandelbar;
	return (mlx);
}

int	free_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img_data->img);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx->img_data);
	free(mlx->props);
	free(mlx);
	exit(0);
}

void	fill_img(t_mlx *mlx)
{
	if (mlx->img_data->img)
		mlx_destroy_image(mlx->mlx, mlx->img_data->img);
	mlx->img_data->img = mlx_new_image(mlx->mlx, WIN_SIZE, WIN_SIZE);
	mlx->img_data->addr = mlx_get_data_addr(mlx->img_data->img, \
							&mlx->img_data->bits_per_pixel, \
							&mlx->img_data->line_length, \
							&mlx->img_data->endian);
	draw_fractal(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img_data->img, 0, 0);
}
