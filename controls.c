/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallaoui <mallaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:40:15 by mallaoui          #+#    #+#             */
/*   Updated: 2023/01/27 18:32:23 by mallaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	zoom_in(t_all *vars, int x, int y)
{
	double	mouse_pos[2];
	double	s;

	mouse_pos[0] = ((x / WIDTH) * (vars->contrl.re_end - \
		vars->contrl.re_start)) + vars->contrl.re_start;
	mouse_pos[1] = ((-y / HEIGHT) * (vars->contrl.im_end - \
		vars->contrl.im_start)) + vars->contrl.im_end;
	vars->contrl.zoom = 0.5;
	s = (vars->contrl.re_end - vars->contrl.re_start) * vars->contrl.zoom;
	vars->contrl.re_end = mouse_pos[0] + (vars->contrl.re_end \
		- mouse_pos[0]) * vars->contrl.zoom;
	vars->contrl.re_start = vars->contrl.re_end - s;
	vars->contrl.im_end = mouse_pos[1] + (vars->contrl.im_end \
		- mouse_pos[1]) * vars->contrl.zoom;
	vars->contrl.im_start = vars->contrl.im_end - s;
}

int	julia_move(int x, int y, t_all *vars)
{
	if (!(x < 0 || x > WIDTH || y < 0 || y > HEIGHT))
	{
		vars->contrl.mouse_x = ((x / WIDTH) * (vars->contrl.re_end - \
			vars->contrl.re_start)) + vars->contrl.re_start;
		vars->contrl.mouse_y = ((-y / HEIGHT) * (vars->contrl.im_end - \
			vars->contrl.im_start)) + vars->contrl.im_end;
	}
	return (0);
}

void	zoom_out(t_all *vars, int x, int y)
{
	double	mouse_pos[2];
	double	s;

	mouse_pos[0] = ((x / WIDTH) * (vars->contrl.re_end - \
		vars->contrl.re_start)) + vars->contrl.re_start;
	mouse_pos[1] = ((-y / HEIGHT) * (vars->contrl.im_end - \
		vars->contrl.im_start)) + vars->contrl.im_end;
	vars->contrl.zoom = 2;
	s = (vars->contrl.re_end - vars->contrl.re_start) * vars->contrl.zoom;
	vars->contrl.re_end = mouse_pos[0] + (vars->contrl.re_end \
		- mouse_pos[0]) * vars->contrl.zoom;
	vars->contrl.re_start = vars->contrl.re_end - s;
	vars->contrl.im_end = mouse_pos[1] + (vars->contrl.im_end \
		- mouse_pos[1]) * vars->contrl.zoom;
	vars->contrl.im_start = vars->contrl.im_end - s;
}

int	control_zoom(int button, int x, int y, t_all *vars)
{
	if (button == 3)
	{
		initialize(vars, vars->av, vars->ac);
		return (0);
	}
	if (button == 5)
		zoom_in(vars, x, y);
	if (button == 4)
		zoom_out(vars, x, y);
	return (0);
}

int	control_key(int keycode, t_all *vars)
{
	double	d;

	d = (vars->contrl.re_end - vars->contrl.re_start) / 10;
	if (keycode == 53)
		exit(1);
	color_shift(keycode, vars);
	if (keycode == 126)
	{
		vars->contrl.im_start += d;
		vars->contrl.im_end += d;
	}
	if (keycode == 123)
	{
		vars->contrl.re_start -= d;
		vars->contrl.re_end -= d;
	}
	control_keys_part2(keycode, vars, d);
	return (0);
}
