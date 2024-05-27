/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydvec3_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:35:13 by ihhrabar          #+#    #+#             */
/*   Updated: 2024/05/27 20:35:14 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yvec3.h"
#include "ytypes.h"

t_dvec3	dvec3_new(double x, double y, double z)
{
	return ((t_dvec3){.x = x, .y = y, .z = z});
}

t_dvec3	dvec3_zero(void)
{
	return ((t_dvec3){.x = 0.0, .y = 0.0});
}

t_dvec3	dvec3_add(t_dvec3 a, t_dvec3 b)
{
	return ((t_dvec3){.x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z});
}

t_dvec3	dvec3_sub(t_dvec3 a, t_dvec3 b)
{
	return ((t_dvec3){.x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z});
}

double	dvec3_dot(t_dvec3 a, t_dvec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
