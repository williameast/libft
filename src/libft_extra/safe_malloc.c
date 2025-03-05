/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weast <weast@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:21:39 by weast             #+#    #+#             */
/*   Updated: 2025/03/03 14:23:26 by weast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void *safe_malloc(size_t bytes)
{
	void *p;

	p = malloc(bytes);
	if (p == NULL)
	{
		ft_putstr_fd("ERROR: Allocation failed. Aborting", 2);
		exit(EXIT_FAILIURE);
	}
	return (p);
}
