/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:34:53 by akonoval          #+#    #+#             */
/*   Updated: 2025/10/22 16:27:55 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**free_split(char **arr, size_t used)
{
	size_t	i;

	i = 0;
	while (i < used)
	{
		free(arr[i]);
		i++;
	}
	free (arr);
	return (NULL);
}

static char	*next_token(char const *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**fill_words(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[j] = next_token(&s[i], c);
			if (!arr[j])
				return (free_split(arr, j));
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (fill_words(s, c, arr));
}
/*
#include <stdio.h>

int main(void)
{
    char **result;
    int i = 0;

    result = ft_split("hello world test", ' ');
    if (!result)
    {
        printf("ft_split returned NULL\n");
        return (1);
    }

    while (result[i])
    {
        printf("[%d] %s\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free (result);
    return (0);
}
*/
