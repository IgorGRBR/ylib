/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymath.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:58:17 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/15 14:58:18 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YMATH_H
# define YMATH_H
# ifndef PRIME_SEARCH_THRESHOLD
#  define PRIME_SEARCH_THRESHOLD 2000
# endif
# include "ytypes.h"

// Return the larger int value between a and b
int		int_max(int a, int b);

// Return the smaller int value between a and b
int		int_min(int a, int b);

// Return the absolute int value of a
int		int_abs(int a);

// Return the sign of a (1 if a > 0, -1 if a < 0 and 0 if a == 0)
int		int_sign(int a);

// Return the larger unsigned int value between a and b
t_uint	uint_max(t_uint a, t_uint b);

// Return the smaller unsigned int value between a and b
t_uint	uint_min(t_uint a, t_uint b);

// Return the larger double value between a and b
double	double_min(double a, double b);

// Return the smaller double value between a and b
double	double_max(double a, double b);

// Return the absolute double value of a
double	double_abs(double a);

// Return the sign of a (1 if a > 0, -1 if a < 0 and 0 if a == 0)
int		double_sign(double a);

// Clamp an integer v between min and max
int		int_clamp(int v, int min, int max);

// Clamp an unsigned integer v between min and max
t_uint	uint_clamp(t_uint v, t_uint min, t_uint max);

// Clamp a double v between min and max
double	double_clamp(double v, double min, double max);
// const double	g_epsilon = 2 ^ -52;

// Perform an integer linear interpolation between a and b
int		int_lerp(int a, int b, double i);

// Perform an unsigned integer linear interpolation between a and b
t_uint	uint_lerp(t_uint a, t_uint b, double i);

// Perform a double linear interpolation between a and b
double	double_lerp(double a, double b, double i);

// Returns the next prime number after num
t_uint	get_next_prime(t_uint num);

#endif
