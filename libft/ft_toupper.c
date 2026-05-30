/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:24:53 by akonoval          #+#    #+#             */
/*   Updated: 2025/10/27 18:41:56 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
#include <stdio.h>

int main(void)
{
	printf("%c\n", ft_toupper('a')); // A
	printf("%c\n", ft_toupper('Z')); // Z
	printf("%c\n", ft_toupper('!')); // !
}
*/