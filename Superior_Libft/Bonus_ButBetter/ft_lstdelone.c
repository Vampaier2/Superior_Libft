/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:49:37 by xalves            #+#    #+#             */
/*   Updated: 2025/06/05 11:15:49 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **head, t_list *node, void (*del)(void *))
{
	if (!*head || !head || !node || !del)
		return ;
	// Update the head
	if (*head == node)
		*head = node->next;
	if (node->prev)
		(node->prev)->next = node->next;
	if (node->next)
		(node->next)->prev = node->prev;
	del(node->content);
	free(node);
}
/*
if (!*head || !head || !node || !del)
Checks:
!*head -> checks if the list is Null
!head -> checks if the pointer to the list head itself is NULL.
!node -> node to delete is Null
!del -> function del is Null
-------------------------------------------------------------

*head = node->next;
->updates the head, to point to the next node. Making the second node the new head.

 */
