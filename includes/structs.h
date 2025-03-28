/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:14:43 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/28 14:02:57 by aadyan           ###   ########.fr       */
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

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	t_data	*img_data;
}	t_mlx;

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
}	t_properties;


#endif
