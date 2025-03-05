/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weast <weast@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:02:54 by weast             #+#    #+#             */
/*   Updated: 2024/06/30 16:11:37 by weast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char *) dst;
	ptr2 = (unsigned char *) src;
	i = 0;
	if (!ptr && !ptr2)
		return (NULL);
	if (ptr2 < ptr)
		while (++i <= len)
			ptr[len - i] = ptr2[len - i];
	else
		while (len-- > 0)
			*(ptr++) = *(ptr2++);
	return (dst);
}
/* #include <string.h> */
/* #include <stdio.h> */

/* int main() { */
/*     char dest[15] = "Hello, World!"; */
/*     const char src[] = "pog cat leg to many"; */
/*     size_t n = strlen(src); */

/*     printf("Original destination string: %s\n", dest); */

/*     ft_memmove(dest + 7, src, n); */

/*     printf("Destination string after memmove: %s\n", dest); */

/*     return 0; */
/* } */
