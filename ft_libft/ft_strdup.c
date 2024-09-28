/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:35:48 by mabrito-          #+#    #+#             */
/*   Updated: 2024/09/21 16:38:51 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*len;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s);
	len = (char *)malloc(sizeof(char) * (size + 1));
	if (!len)
		return (NULL);
	while (s[i])
	{
		len[i] = s[i];
		i++;
	}
	len[i] = '\0';
	return (len);
}
