/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ycstr_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:35:01 by ihhrabar          #+#    #+#             */
/*   Updated: 2024/05/27 20:35:02 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ycstr.h"
#include "ycmem.h"

static t_uint	murmur_32_scramble(t_uint k)
{
	k *= 0xcc9e2d51;
	k = (k << 15) | (k >> 17);
	k *= 0x1b873593;
	return (k);
}

t_uint	_murmur3_32(const t_uchar *key, t_uint len, t_uint seed)
{
	t_uint	h;
	t_uint	k;
	t_uint	i;

	h = seed;
	i = (len >> 2) + 1;
	while (--i)
	{
		ymem_copy(&k, key, sizeof(t_uint));
		key += sizeof(t_uint);
		h ^= murmur_32_scramble(k);
		h = ((h << 13) | (h >> 19)) * 5 + 0xe6546b64;
	}
	k = 0;
	i = (len & 3) + 1;
	while (--i)
	{
		k <<= 8;
		k |= key[i - 1];
	}
	h ^= murmur_32_scramble(k);
	h = (h ^ len) ^ ((h ^ len) >> 16);
	h = (h * 0x85ebca6b) ^ ((h * 0x85ebca6b) >> 13);
	h = (h * 0xc2b2ae35) ^ ((h * 0xc2b2ae35) >> 16);
	return (h);
}

t_uint	cstr_hash(const char *cstr)
{
	return (_murmur3_32((t_uchar *)cstr, cstr_len(cstr), 3985));
}

t_bool	cstr_equal(const char *cstr1, const char *cstr2)
{
	return (cstr_cmp(cstr1, cstr2) == 0);
}
