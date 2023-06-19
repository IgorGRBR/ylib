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

int				int_max(int a, int b);
int				int_min(int a, int b);
int				int_abs(int a);
int				int_sign(int a);
unsigned int	uint_max(unsigned int a, unsigned int b);
unsigned int	uint_min(unsigned int a, unsigned int b);
double			double_min(double a, double b);
double			double_max(double a, double b);
double			double_abs(double a);
int				double_sign(double a);
int				int_clamp(int v, int min, int max);
unsigned int	uint_clamp(int v, int min, int max);
double			double_clamp(double v, double min, double max);
// const double	g_epsilon = 2 ^ -52;

#endif
