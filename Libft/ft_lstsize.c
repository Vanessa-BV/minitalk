/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 13:46:21 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/02/01 13:46:21 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;

	len = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

// int	main(void)
// {
// 	t_list	*list = ft_lstnew("a");
// 	t_list	*new = ft_lstnew("g");
// 	int		len;

// 	ft_lstadd_front(&list, new);
// 	printf("  list: %s\n", (char *)list->content);
// 	len = ft_lstsize(list);
// 	printf("length: %d\n", len);
// 	return (0);
// }