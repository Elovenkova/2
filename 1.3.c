#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int val;
    struct list *next;
} list;

void list_new()
{
    list list_0;
    list_0->next = NULL;
}

int push(list *l, int a)
{
    list *new_i = (list*)malloc(sizeof(list));
    new_i->val = a;
    new_i->next = NULL;
    int count = 0;
    if(l != NULL)
    {
        list *fix = l;
        for( ; fix->next != NULL; fix = fix->next)
        {
            count++;
        }
        fix->next = new_i;
    }
    else
    {
        l = new_i;
    }
    return 1;
}

int pop(list *l, int x)
{
    if(l != NULL)
    {
        list *fix = l;
        while(fix->next != NULL)
            fix = fix->next;
        x = fix->val;
        return 1;
    }
}

int shift(list *l, int x)
{
    if(l != NULL)
    {
        x = l->val;
        return 1;
    }
}

int list_delete(list *l)
{
    if (l)
    {
        list *fix = l;
        list *a = l;
        while(a != NULL)
        {
            a = a->next;
            free(fix);
            fix = a;
        }
        return 1;
    }
    return 0;
}

int unshift(list *l, int a)
{
    list *new_i = (list*)malloc(sizeof(list));
    new_i->val = a;
    new_i->next = l;
    l = new_i;
    return 1;
}
