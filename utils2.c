/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallaoui <mallaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:07:12 by mallaoui          #+#    #+#             */
/*   Updated: 2023/01/28 01:19:39 by mallaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	return_res(char *str, double res, int i, double sign)
{
	int	check_point;
	int	check_pos;
	int	count;

	check_point = -1;
	check_pos = 0;
	count = 0;
	while ((str[i] && (str[i] >= '0' && str[i] <= '9')) || str[i] == '.')
	{
		if (str[i] == 46)
		{
			check_point = i;
			count++;
			i++;
		}
		if (check_point >= 0)
			check_pos++;
		res = res * 10 + (str[i] - '0');
		i++;
	}
	while (check_pos--)
		res /= 10.0;
	return (res * sign);
}
