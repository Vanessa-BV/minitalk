/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 13:51:58 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/02/01 13:51:58 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Descrption:

Input:
1. the original linked list (`lst`)
2. a function for transformation (`f`)
3. a function for freeing memory (`del`)

Notes:
1.The function checks if the transformation and
memory cleanup functions are provided.
If not, it returns `NULL`.
2. It initializes a new linked list (`new_lst`) as `NULL`.
3. It iterates through each element of the
original linked list (`lst`).
4. For each element, it applies the transformation
function (`f`) to the content of the element and
stores the transformed result in `temp_elem`.
5. It creates a new linked list element (`new_elem`)
using the transformed result.
6. If memory allocation fails, it frees the
memory of the already created elements in the new linked
list (`new_lst`) using the memory cleanup function
(`del`) and returns `NULL`.
7. It adds the new element (`new_elem`) to the end of
the new linked list
(`new_lst`) using the `ft_lstadd_back` function.
8. It moves to the next element in the original
linked list (`lst`).
9. Once all elements have been processed, it returns the
new linked list (`new_lst`).
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	t_list	*temp_elem;

	if (!f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		temp_elem = f(lst->content);
		new_elem = ft_lstnew(temp_elem);
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
