/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 04:07:12 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/22 16:43:01 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new;
}

// int	main(void)
// {
// 	// t_list *first = ft_lstnew("first");
// 	// t_list *second = ft_lstnew("second");
// 	// t_list *third = ft_lstnew("third");

// 	// t_list *four = ft_lstnew("four");
// 	// four->next = NULL;

// 	// first->next = second;
// 	// second->next = third;
// 	// third->next = NULL;

// 	// ft_lstadd_back(&first, four);

// 	// printf("%s\n", third->next->content);

// 	t_list *first = ft_lstnew("first");
// 	first = NULL;

// 	t_list *new = ft_lstnew("new");

// 	ft_lstadd_back(&first, new);

// 	printf("%s\n", first->next->content);

// 	return (0);
// }

// int main()
// {
//     t_list *list = NULL; // Initialiser la liste à NULL

//     // Créer un nouvel élément
//     t_list *new_element = malloc(sizeof(t_list));
//     new_element->content = 42;
//     new_element->next = NULL;

//     // Appeler ft_lstadd_back avec *lst initialisé à NULL
//     ft_lstadd_back(&list, new_element);

//     // Vérifier le résultat en imprimant la liste
//     t_list *current = list;
//     while (current != NULL)
//     {
//         printf("%d ", current->content);
//         current = current->next;
//     }
//     printf("\n");

//     // N'oubliez pas de libérer la mémoire allouée pour la liste
//     while (list != NULL)
//     {
//         t_list *temp = list;
//         list = list->next;
//         free(temp);
//     }

//     return (0);
// }
