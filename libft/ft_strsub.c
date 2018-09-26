/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:46:06 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/26 15:50:25 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	slen;
	char			*dst;

	if (!s)
		return (NULL);
	slen = ft_strlen(s) + 1;
	if (slen < start + len)
		return (NULL);
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	ft_strncpy(dst, s + start, len);
	dst[len] = '\0';
	return (dst);
}
