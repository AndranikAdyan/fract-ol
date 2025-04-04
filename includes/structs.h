/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:14:43 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/04 13:50:06 by aadyan           ###   ########.fr       */
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

typedef struct s_properties
{
	double	zoom;
	double	shift_x;
	double	shift_y;
	int		color;
	int		color_queue;
}	t_properties;

typedef struct s_mlx
{
	void			*mlx;
	void			*window;
	t_data			*img_data;
	t_properties	*props;
	int				(*fractal)(t_complex_numbers, int);
}	t_mlx;

#endif
