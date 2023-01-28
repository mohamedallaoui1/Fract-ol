/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallaoui <mallaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:55:02 by mallaoui          #+#    #+#             */
/*   Updated: 2023/01/26 18:04:58 by mallaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	julia(t_all *vars, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		temp;
	int			iter;

	iter = 0;
	c.real = vars->contrl.mouse_x;
	c.imag = vars->contrl.mouse_y;
	z.real = ((x / WIDTH) * (vars->contrl.re_end - \
		vars->contrl.re_start)) + vars->contrl.re_start + vars->contrl.move_x;
	z.imag = ((-y / HEIGHT) * (vars->contrl.im_end - \
		vars->contrl.im_start)) + vars->contrl.im_end + vars->contrl.move_y;
	while (z.real * z.real + z.imag * z.imag < 4 && iter < MAX_ITERATIONS)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.imag * z.real + c.imag;
		z.real = temp;
		iter++;
	}
	if (iter == MAX_ITERATIONS)
		my_mlx_pixel_put(&vars->img, x, y, 0xFFFFFF);
	else
		my_mlx_pixel_put(&vars->img, x, y, vars->contrl.color * iter);
	return (0);
}
