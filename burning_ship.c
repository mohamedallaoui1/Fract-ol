/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallaoui <mallaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:59:27 by mallaoui          #+#    #+#             */
/*   Updated: 2023/01/26 02:35:02 by mallaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	burning_ship(t_all *vars, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		temp;
	int			iter;	

	iter = 0;
	z.real = 0;
	z.imag = 0;
	c.real = ((x / WIDTH) * (vars->contrl.re_end - vars->contrl.re_start)) \
		- 0.5 + vars->contrl.re_start + vars->contrl.move_x;
	c.imag = ((-y / HEIGHT) * (vars->contrl.im_end - vars->contrl.im_start)) \
		+ vars->contrl.im_end + vars->contrl.move_y;
	c.imag *= -1;
	while (z.real * z.real + z.imag * z.imag < 4 && iter < MAX_ITERATIONS)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * fabs(z.imag * z.real) + c.imag;
		z.real = temp;
		iter++;
	}
	if (iter == MAX_ITERATIONS)
		my_mlx_pixel_put(&vars->img, x, y, 0xFFFFFF);
	else
		my_mlx_pixel_put(&vars->img, x, y, vars->contrl.color * iter);
	return (0);
}
