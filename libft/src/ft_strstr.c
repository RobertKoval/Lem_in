/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:33:47 by rkoval            #+#    #+#             */
/*   Updated: 2017/11/17 13:17:08 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned char	*str;
	size_t			len;

	str = (unsigned char*)haystack;
	len = ft_strlen(needle);
	if (len == 0)
		return ((char*)haystack);
	while (*str != '\0' && needle)
	{
		if (ft_strncmp((char*)str, needle, len) == 0)
			return ((char*)str);
		str++;
	}
	return (0);
}
