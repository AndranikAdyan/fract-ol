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
