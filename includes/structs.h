/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:14:43 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/05 19:48:38 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_complex_numbers
{
	double	cx;
	double	cy;
}	t_complex_numbers;

typedef struct s_coords
{
	double	x;
	double	y;
}	t_coords;

typedef struct s_properties
{
	double				zoom;
	double				shift_x;
	double				shift_y;
	int					color;
	int					color_queue;
	int					color_decreasing;
	t_complex_numbers	c_nums;
	t_coords			coords;
}	t_properties;

typedef struct s_mlx
{
	void			*mlx;
	void			*window;
	t_data			*img_data;
	t_properties	*props;
	int				(*fractal)(t_properties);
}	t_mlx;

#endif
