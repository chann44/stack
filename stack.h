#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct Stack {
    int32_t* collection;
    uint32_t cap;
    uint32_t size;
}Stack;


Stack* CreateNewStack(uint32_t cap);
void DeleteStack(Stack** stackp);
bool IsEmpty(Stack* stack);
bool IsFull(Stack* stack);
bool Push(Stack* stack, uint32_t item);
bool Pop(Stack* stack, int32_t* poped);
bool Peek(Stack* stack, int32_t* peek);
