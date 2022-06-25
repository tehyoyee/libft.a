
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void    show(void* content)
{
    printf("%s\n", content);
}

void    *f(void *c)
{
    return "str";
}

int main(void)
{
    t_list *l[3];
    t_list *ptr;

    l[0] = ft_lstnew(ft_strdup("a"));
    l[1] = ft_lstnew(ft_strdup("b"));
    l[2] = ft_lstnew(ft_strdup("c"));


    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%s\n", l[i]->content);
    // }

    ft_lstadd_back(&l[0], l[1]);
    ft_lstadd_back(&l[1], l[2]);

    // ft_lstclear(&l[1], free);
    // ft_lstdelone(l[1], free);
    ptr = ft_lstmap(l[0], &f, free);
    ft_lstiter(l[0], &show);
    ft_lstiter(ptr, &show);
}