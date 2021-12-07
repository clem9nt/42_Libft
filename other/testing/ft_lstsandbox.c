#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void ft_lstprint(t_list *lst)
{
	int i;

	i = 0;
	printf("\n");
	while (lst)
	{
		printf(" [%s] ->", (char *)lst->content);
		if (!(++i % 4))
			printf("\n");
		lst = lst->next;
	}
	printf("NULL/back\n");
	printf("\n");
}

//////////////////////////
//////////////////////////
//////////////////////////

t_list	*ft_lstnew(void *content)
{
	t_list	*first;

	first = malloc(sizeof(t_list));
	if (!first)
		return (NULL);
	first->content = content;
	first->next = NULL;
	return (first);
}

void ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	new->next = *alst;
	*alst = new;
}

int ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
		lst = (count++, lst->next);
	return (count);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

//////////////////////////
//////////////////////////
//////////////////////////

void	ft_lstdelone(t_list *lst)
{
	if ( !lst)
		return ;
	printf("---->%s\n", (char *)lst->content);
	free(lst);
}

int	main(void)
{
	t_list	*head;

	printf("-new-afront-size-print--\n");
	head = ft_lstnew("Initial");
	ft_lstadd_front(&head, ft_lstnew("1st add_front"));
	ft_lstadd_front(&head, ft_lstnew("2nd add_front"));
	// now we have 3 elements
	ft_lstprint(head);
	printf("%i blocks\n", ft_lstsize(head));
	printf("last contain: %s\n", (char *)ft_lstlast(head)->content);
	printf("-aback------------------\n");
	ft_lstadd_back(&head, ft_lstnew("1st add_back"));
	ft_lstadd_back(&head, ft_lstnew("2st add_back"));
	// now we have 5 elements
	ft_lstprint(head);
	printf("%i blocks\n", ft_lstsize(head));
	printf("last contain: %s\n", (char *)ft_lstlast(head)->content);
	printf("-done-------------------\n");
	ft_lstdelone(head);
	return (0);
}
