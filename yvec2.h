/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yvec2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:08:16 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/05/04 12:08:17 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YVEC2_H
# define YVEC2_H
# include "ydefines.h"
# include "ytypes.h"

// int vector
t_ivec2	ivec2_new(int x, int y);
t_ivec2	ivec2_zero(void);
t_ivec2	ivec2_add(t_ivec2 a, t_ivec2 b);
t_ivec2	ivec2_sub(t_ivec2 a, t_ivec2 b);
int		ivec2_dot(t_ivec2 a, t_ivec2 b);
t_ivec2	ivec2_scale(t_ivec2 a, int scalar);
t_ivec2	ivec2_divide(t_ivec2 a, int scalar);
t_ivec2	ivec2_dscale(t_ivec2 a, double scalar);
double	ivec2_length(t_ivec2 a);
double	ivec2_length_sq(t_ivec2 a);
t_bool	ivec2_eq(t_ivec2 a, t_ivec2 b);
t_ivec2	ivec2_negate(t_ivec2 a);
t_dvec2	ivec2_normalized(t_ivec2 a);

// double vector
t_dvec2	dvec2_new(double x, double y);
t_dvec2	dvec2_zero(void);
t_dvec2	dvec2_add(t_dvec2 a, t_dvec2 b);
t_dvec2	dvec2_sub(t_dvec2 a, t_dvec2 b);
double	dvec2_dot(t_dvec2 a, t_dvec2 b);
t_dvec2	dvec2_scale(t_dvec2 a, double scalar);
t_dvec2	dvec2_divide(t_dvec2 a, double scalar);
double	dvec2_length(t_dvec2 a);
double	dvec2_length_sq(t_dvec2 a);
t_dvec2	dvec2_negate(t_dvec2 a);
t_dvec2	dvec2_normalized(t_dvec2 a);

#endif
