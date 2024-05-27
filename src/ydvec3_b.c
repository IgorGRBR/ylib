/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydvec3_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:33:30 by ihhrabar          #+#    #+#             */
/*   Updated: 2024/05/27 20:33:32 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yvec3.h"
#include "ytypes.h"
#include <math.h>

t_dvec3	dvec3_scale(t_dvec3 a, double scalar)
{
	return ((t_dvec3){.x = a.x * scalar, .y = a.y * scalar,
		.z = a.z * scalar});
}

t_dvec3	dvec3_divide(t_dvec3 a, double scalar)
{
	return ((t_dvec3){.x = a.x / scalar, .y = a.y / scalar,
		.z = a.z / scalar});
}

double	dvec3_length(t_dvec3 a)
{
	return (sqrt(dvec3_length_sq(a)));
}

double	dvec3_length_sq(t_dvec3 a)
{
	return ((double)(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_dvec3	dvec3_negate(t_dvec3 a)
{
	return ((t_dvec3){.x = -a.x, .y = -a.y, .z = -a.z});
}
