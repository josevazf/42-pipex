/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:41:18 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 13:08:57 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Adds the node 'new' at the beginning of the list. */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
