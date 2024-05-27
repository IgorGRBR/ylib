/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydvec3_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:16:20 by ihhrabar          #+#    #+#             */
/*   Updated: 2024/05/27 20:16:25 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ytypes.h"
#include "yvec3.h"
#include <math.h>

t_ivec3	dvec3_floor(t_dvec3 a)
{
	return ((t_ivec3){
		.x = (int)floor(a.x),
		.y = (int)floor(a.y),
		.z = (int)floor(a.z),
	});
}

t_dvec2	dvec3_xy(t_dvec3 a)
{
	return ((t_dvec2){.x = a.x, .y = a.y});
}

t_dvec2	dvec3_xz(t_dvec3 a)
{
	return ((t_dvec2){.x = a.x, .y = a.z});
}

t_dvec2	dvec3_yz(t_dvec3 a)
{
	return ((t_dvec2){.x = a.y, .y = a.z});
}
