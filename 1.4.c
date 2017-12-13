#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List{
    char val;
    struct List *next;
} List;

List *push(List *l, char a)
{
    List *new_i = (List*)malloc(sizeof(List));
    new_i->val = a;
    new_i->next = NULL;
    int count = 0;
    if(l != NULL)
    {
        List *fix = l;
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
    return l;
}

char pop(List *l, char x)
{
    if(l != NULL)
    {
        List *fix = l;
        while(fix->next != NULL)
            fix = fix->next;
        x = fix->val;
        return x;
    }
}

List *list_del(List *l) {
	List *list = l;
	List *last;
	if (!l)
		return l;
	if (list->next)
    {
        while(list->next->next != NULL)
            list = list->next;
        last = list->next;
        if (last) {
            list->next = NULL;
            free(last);
        }
        return l;
    }
    else
    {
        l = l->next;
		free(list);
		return l;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    char *word = (char*)malloc(n*sizeof(char));
    int i;
    for(i = 0; i < strlen(word); i++)
    {
        scanf("%c", &word[i]);
    }
    char x;
    List *list = NULL;
    for(i = 0; i < 6; i++)
    {
        if (list == NULL)
        {
            if (word[i] != '}' || word[i] != ')')
            {
                list = push(list, word[i]);
            }
            else
            {
                printf(" NOT OK");
            }
        }
        else
        {
            x = pop(list, x);
            if (word[i] == '}' && x == '{')
            {
                list = list_del(list);
                List *fix = list;
            }
            else if (word[i] == ')' && x == '(')
            {
                list = list_del(list);
            }
            else if (word[i] == '(' || word[i] == '{')
            {
                list = push(list, word[i]);
                List *fix = list;
            }
        }
    }
    if (list)
        printf("NOT OK");
    else
        printf("OK");
    return 0;
}

