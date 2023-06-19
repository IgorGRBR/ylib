/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ycmem.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:49:22 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/20 13:49:23 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YCMEM_H
# define YCMEM_H

void	*ymem_set(void *b, char c, unsigned int len);
void	*ymem_copy(void *dst, const void *src, unsigned int n);

#endif
