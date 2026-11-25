#include <stdio.h>
#include "stack.h"

Stack* CreateNewStack(uint32_t cap)
{
    Stack* stack = malloc(sizeof(Stack));
    if (stack == NULL) {
        return stack; 
    }

    stack->collection = malloc(sizeof(int32_t) * cap);

    if(stack->collection == NULL) {
        free(stack); 
        return NULL;
    }   

    stack->cap = cap;
    stack->size = 0;
    return stack;
}



void DeleteStack(Stack** stackp) 
{
    Stack* stack = *stackp;    
    if (stack == NULL) {
        return; 
    }

    if (stack->collection != NULL) {
            free(stack->collection); 
    }

    free(stack);
    *stackp = NULL;
}


bool IsEmpty(Stack* stack)
{
    return stack->size==0;
}

bool IsFull(Stack* stack)
{

    return stack->size==stack->cap;
}


bool Push(Stack* stack, uint32_t item) 
{
    if (stack == NULL) return false;
    if (IsFull(stack)) return false;

    stack->collection[stack->size] = item;
    stack->size +=1;
    return true;
}

bool Pop(Stack* stack, int32_t* poped) 
{
    if (stack==NULL) return false;
    if (IsEmpty(stack)) return false;

    stack->size -=1;
    *poped = stack->collection[stack->size];
    return true;
}


bool Peak(Stack* stack, int32_t* peek) 
{
    if (stack==NULL) return false;
    if (IsEmpty(stack)) return false;
    *peek = stack->collection[stack->size-1];
    return true;
}



int main() 
{
    Stack* stack = CreateNewStack(10);

    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);
    Push(stack, 4);

    int32_t poped;
    Pop(stack, &poped);
    int32_t peeked;
    Peak(stack, &peeked);

    printf("stack_size %d \n", stack->size);
    printf("stack cap %d \n", stack->cap);
    printf("poped_item %d \n", poped);
    printf("peek %d \n", peeked);
    return 0;
}
