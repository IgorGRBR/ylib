/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymath_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:48:06 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/06/05 14:48:07 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ymath.h"

int	double_sign(double a)
{
	if (a > 0.0)
		return (1);
	else if (a < 0.0)
		return (-1);
	return (0);
}

int	int_lerp(int a, int b, double i)
{
	return (a + (b - a) * i);
}

t_uint	uint_lerp(t_uint a, t_uint b, double i)
{
	return ((t_uint)((int)a + ((int)b - (int)a) * i));
}

double	double_lerp(double a, double b, double i)
{
	return (a + (b - a) * i);
}
