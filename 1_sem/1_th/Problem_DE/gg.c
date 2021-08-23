#include <stdio.h>
#include <stdlib.h>
//........................................
//........................................
typedef int Data;
struct Node {
	struct Node * next;
	struct Node * prev;
	Data data;
};
//........................................
//........................................
void list_init(struct Node * list);

void list_insert(struct Node * list, struct Node * t);
void list_insert_before(struct Node * list, struct Node * t);
void list_remove(struct Node * t);

struct Node * list_push_front(struct Node * list, Data d);
struct Node * list_push_back(struct Node * list, Data d);

Data list_pop_front(struct Node * list);
Data list_pop_back(struct Node * list);
Data list_delete(struct Node * t);

void list_print (struct Node * list);
int list_is_empty(struct Node * list);

void list_clear(struct Node * list);
//........................................
//........................................
int main()
{
    struct Node * a = malloc(sizeof(struct Node));
    struct Node * b = malloc(sizeof(struct Node));
    struct Node * c = malloc(sizeof(struct Node));
    b->data = 228;
    c->data = 322;
    int x = 0;
    list_init(a);
    list_insert(a, b);
    list_print(a);
    list_clear(a);

    list_insert(a, c);
    list_print(a);
    list_clear(a);
    list_print(a);
    list_remove(a);
    x = list_is_empty(a);
    printf("x = %d\n", x);
    //list_print(a);
}
//........................................
//........................................
int flag = 0;

void list_init(struct Node* list)
{
   // flag = 0;
    list->next = list;
    list->prev = list;
    return;
}
//........................................
// вставляет элемент t после элемента list
void list_insert(struct Node * list, struct Node * t)
{
    t->next = list->next;
    t->prev = list;

    list->next->prev = t;
    list->next = t;

    return;
}
//........................................
// вставляет элемент t перед элементом list
void list_insert_before(struct Node * list, struct Node * t)
{
    t->next = list;
    t->prev = list->prev;

    list->prev->next = t;
    list->prev = t;

    return;
}
//........................................
// удаляет элемент t из списка
void list_remove(struct Node * t)
{
    if(t->next = t)
    {
        free(t);
        flag = 1;
        return;
    }
    t->next->prev = t->prev;
    t->prev->next = t->next;


    //free(t);
    return;
}
//........................................
// печатает список
void list_print (struct Node * list)
{
    struct Node* tmp = list->next;

    while(tmp != list)
    {
        if(tmp->next == list)
            printf("%d\n", tmp->data);
        else
            printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    return;
}
//........................................
//вставляет элемент в голову
struct Node * list_push_front(struct Node * list, Data d)
{
    struct Node* new = calloc(1, sizeof(struct Node));
    if(new == NULL)
        return NULL;
    new->data = d;
    list_insert(list, new);

    return new;
}
//........................................
//вставляет элемент в хвост
struct Node * list_push_back(struct Node * list, Data d)
{
    struct Node* new = calloc(1, sizeof(struct Node));
    if(new == NULL)
        return NULL;
    new->data = d;
    list_insert_before(list, new);

    return new;
}
//........................................
//удаляет голову (хвост, указанный элемент t) списка, возвращая данные.
Data list_pop_front(struct Node * list)
{
    Data tmp = list->next->data;
    struct Node* freedom = list->next;
    list->next = list->next->next;
    free(freedom);
    return tmp;
}
//........................................
//удаляет голову (хвост, указанный элемент t) списка, возвращая данные.
Data list_pop_back(struct Node * list)
{
    Data tmp = list->prev->data;
    struct Node* freedom = list->prev;
    list->prev = list->prev->prev;
    free(freedom);
    return tmp;
}
//........................................
//удаляет голову (хвост, указанный элемент t) списка, возвращая данные.
Data list_delete(struct Node * t)
{
    Data tmp = t->data;
    struct Node* freedom = t;
    list_remove(t);
    free(freedom);
    return tmp;
}
//........................................
//........................................
int list_is_empty(struct Node * list)
{
    if(list == NULL)
        return 1;
    else
        return 0;
}
//........................................
//опустошает список, освобождая память. После этого можно опять добавлять элементы в список.
void list_clear(struct Node * list)
{
    struct Node* ptr = list->next;
    struct Node* prev = NULL;
    while(ptr != list)
    {
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
    list->next = list;
    list->prev = list;
    return;
}
