/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yivec3_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:30:20 by ihhrabar          #+#    #+#             */
/*   Updated: 2024/05/27 20:30:22 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yvec3.h"
#include "ytypes.h"

t_ivec3	ivec3_new(int x, int y, int z)
{
	return ((t_ivec3){.x = x, .y = y, .z = z});
}

t_ivec3	ivec3_zero(void)
{
	return ((t_ivec3){.x = 0, .y = 0, .z = 0});
}

t_ivec3	ivec3_add(t_ivec3 a, t_ivec3 b)
{
	return ((t_ivec3){.x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z});
}

t_ivec3	ivec3_sub(t_ivec3 a, t_ivec3 b)
{
	return ((t_ivec3){.x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z});
}

int	ivec3_dot(t_ivec3 a, t_ivec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
