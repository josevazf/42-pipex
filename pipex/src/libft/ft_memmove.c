/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:20:44 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 14:33:51 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies the values of 'len' bytes from the location pointed by 'src' 
   to the memory block pointed by 'dest'. */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (src > dest)
		d = ft_memcpy(dest, src, len);
	else
	{
		while (len--)
			d[len] = s[len];
	}
	return (d);
}

/* int	main(void)
{
	int i = -1;
	char s1[] = "Ola 42 ola!";
	int s11[] = {42, 45, 68, 1, 4, 6};
	char s2[10];
	char s3[10];
	int s22[10];
	ft_memmove(s22, s11, 16);
	int s222[10];
	memmove(s222, s11, 16);

	printf("%s | %s\n", ft_memmove(s2, s1, 5), memmove(s2, s1, 5));
	while (++i < 4)
		printf("%i | %i\n", s22[i], s222[i]);
	printf("%s | %s\n", ft_memmove(s3, s1, 2), memmove(s3, s1, 2));
} */