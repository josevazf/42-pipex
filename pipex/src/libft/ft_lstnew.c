/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:38:04 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 13:16:52 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates and returns a new node.
   The member variable ’content’ is initialized with 
   the value of the parameter ’content’. 
   The variable ’next’ is initialized to NULL. */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
