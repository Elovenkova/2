#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct DATA {
    char *name;
    char *number;
    struct DATA* next;
    struct DATA* prev;
} DATA;

DATA* SINGLE_DATA(char *name, char *number)
{
    DATA* pstr = malloc(sizeof(DATA));
    pstr->name = name;
    pstr->number = number;
    pstr->next = NULL;
    pstr->prev = NULL;
    return pstr;
}


DATA *INSERT(DATA* D_0, DATA* D_c)
{
    DATA* D_n = D_0->next;
    D_0->next = D_c;
    D_c->prev = D_0;
    D_c->next = D_n;
    if(D_n != NULL)
    {
        D_n->prev = D_c;
    }
    return D_0;
}

DATA *FIND(DATA* D_t, char *name)
{
    DATA* element;
    if (D_t->next)
    {
        element = D_t->next;
        int cmp = 1;
        while (cmp != 0 && element->next)
        {
            cmp = strcmp(name, element->name);
            if (cmp == 0)
                return element;
            else
            {
                if (element->next)
                    element = element->next;
                if (element->next == NULL && strcmp(name, element->name) == 0)
                    return element;
            }
        }
        if (cmp == 0)
            return element;
        else
            return NULL;
    }
    else
    {
        element = NULL;
        return element;
    }
}

int main()
{
    char no_name[80] = "NULL";
    char no_number[80] = "NULL";
    DATA* data_0 = SINGLE_DATA(no_name, no_number);
    FILE* note;
    if( (note = fopen("file.txt","r")) == NULL )
    {
        printf("Can not open file!\n");
        return -1;
    }
    char in[80] = "INSERT";
    char str[1000];
    while(fscanf(note,"%s", &str) != EOF)
    {
        if (strcmp(str, in) == 0)
        {
            fscanf(note,"%s", &str);
            int len1 = strlen(str);
            char *NAME = (char *)malloc(len1 * sizeof(str));
            strcpy(NAME, str);
            fscanf(note,"%s", &str);
            int len2 = strlen(str);
            char *NUMBER = (char *)malloc(len2 * sizeof(str));
            strcpy(NUMBER, str);
            DATA* data_c = SINGLE_DATA(NAME, NUMBER);
            DATA* exist = FIND(data_0, NAME);
            if (exist == NULL)
            {
                data_0 = INSERT(data_0, data_c);
                printf("\nOK\n");
            }
            else
            {
                printf("\nChanged. Old Value = %s", exist->number);
                strcpy(exist->number, NUMBER);
            }
        }
        else
        {
            fscanf(note,"%s", &str);
            int len1 = strlen(str);
            char *NAME = (char *)malloc(len1 * sizeof(str));
            strcpy(NAME, str);
            DATA* exist = FIND(data_0, NAME);
                if (exist == NULL)
                    printf("\nNO");
                else
                {
                    printf("\n%s", exist->number);
                }
        }
    }
    return 0;
}
