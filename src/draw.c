/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   draw.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aadyan <marvin@42.fr>					  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/27 11:50:12 by aadyan			#+#	#+#			 */
/*   Updated: 2025/03/27 12:13:21 by aadyan		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(int x, int y, t_data *img, int color)
{
	char	*pixel_addr;

	if (x < 0 || y < 0 || x > WIN_SIZE || y > WIN_SIZE)
		return ;
	pixel_addr = img->addr + (y * img->line_length + x * \
		(img->bits_per_pixel / 8));
	*(unsigned int *)pixel_addr = color;
}

void	draw_fractal(t_data *img, t_properties *props, int (*fractal)(t_complex_numbers *, int))
{
	int					x;
	int					y;
	int					iter;
	int					iter_next;
	t_complex_numbers	*c_nums;

	y = 0;
	while (y < WIN_SIZE - 1)
	{
		x = 0;
		while (x < WIN_SIZE - 1)
		{
			c_nums = get_complex_nums(x, y, props);
			iter = fractal(c_nums, MAX_ITER);
			free(c_nums);
			c_nums = get_complex_nums(x + 1, y, props);
			iter_next = fractal(c_nums, MAX_ITER);
			free(c_nums);
			if (abs(iter - iter_next) > 1)
				draw_pixel(x, y, img, props->color);
			++x;
		}
		++y;
	}
}
