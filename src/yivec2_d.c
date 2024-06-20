/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yivec2_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:37:22 by ihhrabar          #+#    #+#             */
/*   Updated: 2024/05/27 20:37:23 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ytypes.h"
#include "yvec2.h"

t_ivec2	ivec2_mul(t_ivec2 a, t_ivec2 b)
{
	return ((t_ivec2){.x = a.x * b.x, .y = a.y * b.y});
}

t_ivec2	ivec2_div(t_ivec2 a, t_ivec2 b)
{
	return ((t_ivec2){.x = a.x / b.x, .y = a.y / b.y});
}

t_ivec2	ivec2_lerp(t_ivec2 a, t_ivec2 b, double i)
{
	return (ivec2_add(a, ivec2_dscale(ivec2_sub(b, a), i)));
}
