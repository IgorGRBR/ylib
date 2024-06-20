/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yivec3_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:33:07 by ihhrabar          #+#    #+#             */
/*   Updated: 2024/05/27 20:33:08 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yvec3.h"
#include "ytypes.h"

t_ivec3	ivec3_negate(t_ivec3 a)
{
	return ((t_ivec3){.x = -a.x, .y = -a.y, .z = -a.z});
}

t_ivec3	ivec3_dscale(t_ivec3 a, double scalar)
{
	return ((t_ivec3){.x = (int)(a.x * scalar), .y = (int)(a.y * scalar),
		.z = (int)(a.z * scalar)});
}

t_dvec3	ivec3_normalized(t_ivec3 a)
{
	return (dvec3_normalized(dvec3_new((double)a.x, (double) a.y,
				(double) a.z)));
}

t_ivec3	ivec3_lerp(t_ivec3 a, t_ivec3 b, double i)
{
	return (ivec3_add(a, ivec3_dscale(ivec3_sub(b, a), i)));
}
