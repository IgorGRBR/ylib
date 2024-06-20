/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yvec3.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:36:26 by ihhrabar          #+#    #+#             */
/*   Updated: 2024/05/27 20:36:27 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YVEC3_H
# define YVEC3_H
# include "ytypes.h"

// Create a new integer vector with specified x and y components
t_ivec3	ivec3_new(int x, int y, int z);

// Create a new integer vector with x and y being equal to 0
t_ivec3	ivec3_zero(void);

// Sum of 2 int 3D vectors
t_ivec3	ivec3_add(t_ivec3 a, t_ivec3 b);

// Difference of 2 3D int vectors
t_ivec3	ivec3_sub(t_ivec3 a, t_ivec3 b);

// Element-wise multiplication of 2 3D int vectors
t_ivec3	ivec3_mul(t_ivec3 a, t_ivec3 b);

// Element-wise division of 2 3D int vectors
t_ivec3	ivec3_div(t_ivec3 a, t_ivec3 b);

// Dot product of 2 3D int vectors
int		ivec3_dot(t_ivec3 a, t_ivec3 b);

// Cross product of 2 3D int vectors
t_dvec3	ivec3_cross(t_ivec3 a, t_ivec3 b);

// Int 3D vector scaled by int scalar
t_ivec3	ivec3_scale(t_ivec3 a, int scalar);

// Int 3D vector scaled by 1/scalar
t_ivec3	ivec3_divide(t_ivec3 a, int scalar);

// Int 3D vector scaled by double scalar
t_ivec3	ivec3_dscale(t_ivec3 a, double scalar);

// Length of an int 3D vector
double	ivec3_length(t_ivec3 a);

// Squared length of an int 3D vector
double	ivec3_length_sq(t_ivec3 a);

// Check if 2 int 3D vectors are equal
t_bool	ivec3_eq(t_ivec3 a, t_ivec3 b);

// Inverse of an int 3D vector
t_ivec3	ivec3_negate(t_ivec3 a);

// Normalized vector that points to the same direction as the int 3D vector
t_dvec3	ivec3_normalized(t_ivec3 a);

// Form a new ivec2 out of x and y components of ivec3
t_ivec2	ivec3_xy(t_ivec3 a);

// Form a new ivec2 out of x and z components of ivec3
t_ivec2	ivec3_xz(t_ivec3 a);

// Form a new ivec2 out of x and z components of ivec3
t_ivec2	ivec3_yz(t_ivec3 a);

// Performs a linear interpolation between a and b
t_ivec3	ivec3_lerp(t_ivec3 a, t_ivec3 b, double i);

// Create a new double 3D vector with specified x and y components
t_dvec3	dvec3_new(double x, double y, double z);

// Create a new double 3D vector with x and y being equal to 0.0
t_dvec3	dvec3_zero(void);

// Sum of 2 double 3D vectors
t_dvec3	dvec3_add(t_dvec3 a, t_dvec3 b);

// Difference of 2 double 3D vectors
t_dvec3	dvec3_sub(t_dvec3 a, t_dvec3 b);

// Element-wise multiplication of 2 3D double vectors
t_dvec3	dvec3_mul(t_dvec3 a, t_dvec3 b);

// Element-wise division of 2 3D double vectors
t_dvec3	dvec3_div(t_dvec3 a, t_dvec3 b);

// Dot product of 2 double 3D vectors
double	dvec3_dot(t_dvec3 a, t_dvec3 b);

// Cross product of 2 double 3D vectors
t_dvec3	dvec3_cross(t_dvec3 a, t_dvec3 b);

// Double 3D vector scaled by double scalar
t_dvec3	dvec3_scale(t_dvec3 a, double scalar);

// Double 3D vector scaled by 1/scalar
t_dvec3	dvec3_divide(t_dvec3 a, double scalar);

// Length of a double 3D vector
double	dvec3_length(t_dvec3 a);

// Squared length of a double 3D vector
double	dvec3_length_sq(t_dvec3 a);

// Inverse of a double 3D vector
t_dvec3	dvec3_negate(t_dvec3 a);

// Normalized vector that points to the same direction as the double 3D vector
t_dvec3	dvec3_normalized(t_dvec3 a);

// Apply floor to dvec3 components and return ivec3
t_ivec3	dvec3_floor(t_dvec3 a);

// Form a new ivec2 out of x and y components of ivec3
t_dvec2	dvec3_xy(t_dvec3 a);

// Form a new ivec2 out of x and z components of ivec3
t_dvec2	dvec3_xz(t_dvec3 a);

// Form a new ivec2 out of x and z components of ivec3
t_dvec2	dvec3_yz(t_dvec3 a);

// Performs a linear interpolation between a and b
t_dvec3	dvec3_lerp(t_dvec3 a, t_dvec3 b, double i);

#endif
