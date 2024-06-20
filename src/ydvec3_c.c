/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydvec3_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:30:29 by ihhrabar          #+#    #+#             */
/*   Updated: 2024/05/27 20:30:30 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ytypes.h"
#include "yvec3.h"

t_dvec3	dvec3_normalized(t_dvec3 a)
{
	return (dvec3_divide(a, dvec3_length(a)));
}

t_dvec3	dvec3_mul(t_dvec3 a, t_dvec3 b)
{
	return ((t_dvec3){.x = a.x * b.x, .y = a.y * b.y, .z = a.z * b.z});
}

t_dvec3	dvec3_div(t_dvec3 a, t_dvec3 b)
{
	return ((t_dvec3){.x = a.x / b.x, .y = a.y / b.y, .z = a.z / b.z});
}

t_dvec3	dvec3_cross(t_dvec3 a, t_dvec3 b)
{
	return ((t_dvec3){.x = a.y * b.z - a.z * b.y,
		.y = a.z * b.x - a.x * b.z,
		.z = a.x * b.y - a.y * b.x});
}

t_dvec3	dvec3_lerp(t_dvec3 a, t_dvec3 b, double i)
{
	return (dvec3_add(a, dvec3_scale(dvec3_sub(b, a), i)));
}
