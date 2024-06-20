/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydvec2_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:33:57 by ihhrabar          #+#    #+#             */
/*   Updated: 2024/05/27 20:33:58 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ytypes.h"
#include "yvec2.h"
#include <math.h>

t_dvec2	dvec2_mul(t_dvec2 a, t_dvec2 b)
{
	return ((t_dvec2){.x = a.x * b.x, .y = a.y * b.y});
}

t_dvec2	dvec2_div(t_dvec2 a, t_dvec2 b)
{
	return ((t_dvec2){.x = a.x / b.x, .y = a.y / b.y});
}

t_ivec2	dvec2_floor(t_dvec2 a)
{
	return ((t_ivec2){.x = (int)floor(a.x), .y = (int)floor(a.y)});
}

t_dvec2	dvec2_lerp(t_dvec2 a, t_dvec2 b, double i)
{
	return (dvec2_add(a, dvec2_scale(dvec2_sub(b, a), i)));
}
