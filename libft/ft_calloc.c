/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:57:11 by akonoval          #+#    #+#             */
/*   Updated: 2025/10/20 16:05:28 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	if (count && size && count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
/*
#include <stdio.h>

int main(void)
{
    int *arr = ft_calloc(5, sizeof(int));

    if (!arr)
        return (1);

    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);  // should print 0 0 0 0 0
    printf("\n");

    free(arr);
    return (0);
}*/