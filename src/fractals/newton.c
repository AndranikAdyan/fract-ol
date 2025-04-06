/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 10:54:22 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/06 10:54:35 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "fractol.h"

static t_complex_numbers	newton_formula(t_complex_numbers z)
{
	t_complex_numbers	f;
	double				zx2;
	double				zxy;

	zx2 = z.cx * z.cx - z.cy * z.cy;
	zxy = 2 * z.cx * z.cy;
	f.cx = z.cx * zx2 - z.cy * zxy - 1.0;
	f.cy = z.cx * zxy + z.cy * zx2;
	return (f);
}

static t_complex_numbers	newton_derivative(t_complex_numbers z)
{
	t_complex_numbers	df;

	df.cx = 3.0 * (z.cx * z.cx - z.cy * z.cy);
	df.cy = 6.0 * z.cx * z.cy;
	return (df);
}

static t_complex_numbers	newton_next(t_complex_numbers z, t_complex_numbers f, t_complex_numbers df)
{
	t_complex_numbers	tmp;
	double				denom;
	double				denom_inv;

	denom = df.cx * df.cx + df.cy * df.cy;
	denom_inv = 1.0 / denom;
	tmp.cx = z.cx - (f.cx * df.cx + f.cy * df.cy) * denom_inv;
	tmp.cy = z.cy - (f.cy * df.cx - f.cx * df.cy) * denom_inv;
	return (tmp);
}

int	newton(t_properties props)
{
	t_complex_numbers	z;
	t_complex_numbers	f;
	t_complex_numbers	df;
	t_complex_numbers	next;
	int					iter;

	z = props.c_nums;
	iter = 0;
	while (iter < MAX_ITER)
	{
		f = newton_formula(z);
		df = newton_derivative(z);
		next = newton_next(z, f, df);
		if ((next.cx - z.cx) * (next.cx - z.cx) + \
			(next.cy - z.cy) * (next.cy - z.cy) < 1e-6)
			break ;
		z = next;
		iter++;
	}
	return (iter);
}
