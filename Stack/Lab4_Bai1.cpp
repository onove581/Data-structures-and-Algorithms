#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
  
// Khoi tao stack
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
// tao stack
struct Stack* createStack( unsigned capacity ) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
  
    if (!stack) return NULL; 
  
    stack->top = -1; 
    stack->capacity = capacity; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 
  
    if (!stack->array) return NULL; 
  
    return stack; 
} 
// kiem tra stack co rong hay khong
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1 ; 
} 
  
char peek(struct Stack* stack) 
{ 
    return stack->array[stack->top]; 
} 
  
char pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 
//them 1 pt vao stack
void push(struct Stack* stack, char op) 
{ 
    stack->array[++stack->top] = op; 
} 
//tinh gí tri hau to
int evaluatePostfix(char* exp) 
{ 
    // Tao 1 stack
    struct Stack* stack = createStack(strlen(exp)); 
    int i; 
    if (!stack) return -1; 
    for (i = 0; exp[i]; ++i) 
    {  
        if (isdigit(exp[i])) 
            push(stack, exp[i] - '0'); 
        else
        { 
            int val1 = pop(stack); 
            int val2 = pop(stack); 
            switch (exp[i]) 
            { 
            case '+': push(stack, val2 + val1); break; 
            case '-': push(stack, val2 - val1); break; 
            case '*': push(stack, val2 * val1); break; 
            case '/': push(stack, val2/val1); break; 
            } 
        } 
    } 
    return pop(stack); 
} 
  

int main() 
{ 
    char exp[50];
    printf("\nNhap biet thuc hau to: ");
    gets(exp);
    printf ("Gia tri cua bieu thuc hau to: %d", evaluatePostfix(exp)); 
    return 0; 
} 

