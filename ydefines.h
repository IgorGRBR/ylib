/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydefines.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:07 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/20 13:41:08 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YDEFINES_H
# define YDEFINES_H
# ifndef YNULL
#  define YNULL 0
// #  define YNULL (void *)0
// You might be asking why I commented out a perfectly fine line, and instead
// replaced it with something arguably worse. Its norminette. Its because
// norm doesn't allow non-constant expressions/statements in preprocessor, and
// according to norminette, "(void *)0" is not a constant. Fuck norminette.

// A function call replacement for a proper YNULL macro
void	*ynull(void);
# endif
#endif
