/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:41:18 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 13:08:28 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Adds the node 'new' at the end of the list. */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{	
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
