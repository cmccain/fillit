/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:18:14 by cmccain           #+#    #+#             */
/*   Updated: 2016/12/06 16:39:12 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_reverse(t_list *lst)
{
	t_list	*tmp1;
	t_list	*cur;
	t_list	*tmp2;

	tmp1 = NULL;
	cur = lst;
	while (cur != NULL)
	{
		tmp2 = cur->next;
		cur->next = tmp1;
		tmp1 = cur;
		cur = tmp2;
	}
	lst = tmp1;
	return (lst);
}
